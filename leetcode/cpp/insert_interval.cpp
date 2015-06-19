#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef struct Interval {
	int start;
	int end;
	Interval() : start(0), end(0) {}
	Interval(int s, int e) : start(s), end(e) {}
} Interval;

bool compareStart(const Interval& interval, int val) {
	return interval.end < val;
}

bool compareEnd(int val, const Interval& interval) {
	return val < interval.start;
}
class Solution {
	public:
		vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
			vector<Interval> ans = intervals;
			if (newInterval.start > newInterval.end)
				return ans;
			auto first = lower_bound(ans.begin(), ans.end(), newInterval.start, compareStart);
			auto second = upper_bound(ans.begin(), ans.end(), newInterval.end, compareEnd);
			// cout << "[" << first->start << "," << first->end << "]" << endl;
			// cout << "[" << second->start << "," << second->end << "]" << endl;
			if (first < second) {
				int mergeLower = min(first->start, newInterval.start);
				second--;
				int mergeUpper = max(second->end, newInterval.end);
				second->start = mergeLower;
				second->end = mergeUpper;
				ans.erase(first, second);
			} 
			else if (first == second) {
				ans.insert(first, newInterval);
			}
			return ans;
		}
};

void print(const vector<Interval>& intervals) {
	for (const auto& interval: intervals) {
		cout << "[" << interval.start << "," << interval.end << "]";
	}
	cout << endl;
}

int main() {

	vector<Interval> ints;
	ints.push_back(Interval(1,5));
	// ints.push_back(Interval(3,4));
	// ints.push_back(Interval(7,8));
	// ints.push_back(Interval(9,10));
	// ints.push_back(Interval(15,17));
	Interval newInterval(1,1);
	cout << "[" << newInterval.start << "," << newInterval.end << "] => "; 
	print(ints);
	
	Solution s;
	ints = s.insert(ints, newInterval);
	print(ints);
}
