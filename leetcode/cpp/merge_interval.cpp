struct Interval {
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
}

class Solution {
public:
    vector<Interval> merge(vector<Interval>& intervals) {
        vector<Interval> ints;
        sort(intervals.begin(), intervals.end(), compareFunc);
        for (const auto& i: intervals) {
            if (ints.empty())
                ints.push_back(i);
            else {
                if (i.start > ints[ints.size()-1].end)
                    ints.push_back(i);
                else {
                    ints[ints.size()-1].end = max(i.end, ints[ints.size()-1].end);
                }
            }
        }
        return ints;
    }
private:
    static bool compareFunc(Interval i, Interval j) { return i.start < j.start; }

};