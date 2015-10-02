#include <vector>
#include <queue>
#include <deque>
#include <algorithm>
#include <sstream>
#include <iostream>
#include <cassert>
using namespace std;
vector<int> maxSlidingWindow(vector<int>& nums, int k) {
		deque<int> q;
		vector<int> output;
		int n = nums.size();
		for (int i=0; i<n; i++) {
			while (q.size() > 0 && nums[q.back()] <= nums[i])
				q.pop_back();
			q.push_back(i);
			while (q.front() <= i - k)
				q.pop_front();
			if (i >= k-1) {
				output.push_back(nums[q.front()]);
			}
		}
		return output;
}
string toString(vector<int> v) {
	stringstream ss;
	ss << '[';
	for (int i=0; i<v.size(); i++) {
		if (i > 0)
			ss << ",";
		ss << v[i];
	}
	ss << ']';
	return ss.str();
}
int main() {
	
	vector<int> v1 = {1,3,-1,-3,5,3,6,7};
	assert(toString(maxSlidingWindow(v1, 3)) == "[3,3,5,5,6,7]");
	vector<int> v2 = {1,-1};
	assert(toString(maxSlidingWindow(v2, 1)) == "[1,-1]");
	vector<int> v3 = {7,2,4};
	assert(toString(maxSlidingWindow(v3, 2)) == "[7,4]");
	vector<int> v4 = {1,3,1,2,0,5};
	assert(toString(maxSlidingWindow(v4, 3)) == "[3,3,2,5]");
}