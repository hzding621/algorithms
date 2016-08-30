#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Interval {
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};

class SummaryRanges {
public:
    /** Initialize your data structure here. */
    SummaryRanges() {

    }

    void addNum(int val) {
        // first intervals that end at or after val
        auto after = lower_bound(_intervals.begin(), _intervals.end(), val,
                                 [](const Interval& interval, int v) { return interval.end < v; });
        if (after != _intervals.end() && after->start <= val) {
            // val intersects with current intervals
            return;
        }

        // val intersect with no interval
        Interval newInterval(val, val);
        bool merged = false;
        if (after != _intervals.end()) {
            if (after->start == val + 1) {
                // merge val into after
                after->start = val;
                merged = true;
            }
        }
        if (after != _intervals.begin()) {
            auto before = after - 1;
            if (before->end == val - 1) {
                // merge val into before
                before->end = val;
                merged = true;
            }
            if (after != _intervals.end() && before->end == after->start) {
                // merge before and after
                before->end = after->end;
                _intervals.erase(after);
            }
        }

        if (!merged) {
            // insert (val, val) as a new interval
            _intervals.insert(after, Interval(val, val));
        }
    }

    vector<Interval> getIntervals() {
        return _intervals;
    }
private:
    vector<Interval> _intervals;
};

int main() {

    SummaryRanges summaryRanges;
    summaryRanges.addNum(1);
    summaryRanges.addNum(3);
    summaryRanges.addNum(7);
    summaryRanges.addNum(2);
    summaryRanges.addNum(6);
    summaryRanges.addNum(9);
    summaryRanges.addNum(4);
    summaryRanges.addNum(10);
    summaryRanges.addNum(5);
    summaryRanges.addNum(8);

    return 0;
}