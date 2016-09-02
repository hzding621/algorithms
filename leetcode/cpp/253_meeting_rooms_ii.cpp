#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

struct Interval {
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};

class Solution {
public:
    int minMeetingRooms(vector<Interval>& intervals) {
        // Sweep Line Algorithm

        vector<pair<int, bool>> events;
        for (auto& intv: intervals) {
            // 0 is leave, 1 is enter, leave events happen before enter
            events.push_back(make_pair(intv.start, 1));
            events.push_back(make_pair(intv.end, 0));
        }

        sort(events.begin(), events.end());

        int rooms = 0, maxRooms = 0;
        for (auto& e: events) {
            if (e.second) {
                rooms++;
            } else {
                rooms--;
            }
            maxRooms = max(maxRooms, rooms);
        }
        return maxRooms;
    }
};

int main() {

    vector<Interval> intervals = {
            {0, 30},
            {5, 10},
            {15, 20}
    };

    Solution sol;
    cout << sol.minMeetingRooms(intervals) << endl;

}

