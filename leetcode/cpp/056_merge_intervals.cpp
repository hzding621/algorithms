struct Interval {
  int start;
  int end;
  Interval() : start(0), end(0) {}
  Interval(int s, int e) : start(s), end(e) {}
};

bool compareIntervals(Interval i, Interval j) {
    return i.start < j. start;
}
class Solution {
public:
    vector<Interval> merge(vector<Interval>& intervals) {
        sort(intervals.begin(), intervals.end(), compareIntervals);
        vector<Interval> result;
        for (Interval& i: intervals) {
            if (result.empty() || i.start > result.back().end)
                result.push_back(i);
            else
                result.back().end = max(result.back().end, i.end);
        }
        return result;
    }
};