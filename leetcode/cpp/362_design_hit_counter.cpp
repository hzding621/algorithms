#include <iostream>
#include <deque>
#include <utility>

using namespace std;

class HitCounter {
public:
    /** Initialize your data structure here. */
    HitCounter() {
        _recentHitsCount = 0;
        _currentTimestamp = 0;
    }
    
    /** Record a hit.
        @param timestamp - The current timestamp (in seconds granularity). */
    void hit(int timestamp) {
        _recentHitsCount++;
        if (!_recentHits.empty() && timestamp == _recentHits.back().first) {
            _recentHits.back().second++;
        } else {
            _recentHits.emplace_back(timestamp, 1);
        }
        updateRecent(timestamp);
    }
    
    /** Return the number of hits in the past 5 minutes.
        @param timestamp - The current timestamp (in seconds granularity). */
    int getHits(int timestamp) {
        updateRecent(timestamp);
        return _recentHitsCount;
    }
private:
    deque<pair<int,int>> _recentHits;
    int _recentHitsCount;
    int _currentTimestamp;

    void updateRecent(int timestamp) {
        _currentTimestamp = timestamp;
        while (!_recentHits.empty() && _recentHits.front().first <= _currentTimestamp - 300) {
            _recentHitsCount -= _recentHits.front().second;
            _recentHits.pop_front();
        }
    }
};


int main() {

    HitCounter counter;
    counter.hit(1);
    counter.hit(1);
    counter.hit(1);
    counter.hit(300);
    cout << counter.getHits(300) << endl;


    return 0;
}