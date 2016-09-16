#include <iostream>
#include <queue>
#include <stack>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <map>
#include <set>
#include <utility>

using namespace std;

class MovingAverage {
public:
    /** Initialize your data structure here. */
    MovingAverage(int size) : _size(size) {}

    double next(int val) {
        currentSum += val;
        _currentElements.push(val);
        if (_currentElements.size() > _size) {
            int earliest = _currentElements.front();
            _currentElements.pop();
            currentSum -= earliest;
        }
        return currentSum / _currentElements.size();
    }

private:
    double currentSum = 0;
    int _size;
    queue<int> _currentElements;
};

int main() {

    MovingAverage movingAverage(3);
    cout << movingAverage.next(1) << endl;
    cout << movingAverage.next(10) << endl;
    cout << movingAverage.next(3) << endl;
    cout << movingAverage.next(5) << endl;

    return 0;
}