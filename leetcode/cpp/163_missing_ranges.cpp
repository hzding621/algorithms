#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
	vector<string> findMissingRanges(vector<int>& nums, int lower, int upper) {
		vector<string> result;
		int i = 0;
		while (i < nums.size() && nums[i] < lower)
			i++;
		if (i == nums.size()) {
			if (lower < upper)
				result.push_back(to_string(lower) + "->" + to_string(upper));
			else if (lower == upper)
				result.push_back(to_string(lower));
			return result;
		}
		if (nums[i] > lower + 1)
			result.push_back(to_string(lower) + "->" + to_string(nums[i]-1));
		else if (nums[i] > lower)
			result.push_back(to_string(lower));
		i++;
		while (i < nums.size() && nums[i] <= upper) {
			if (nums[i] > nums[i-1] + 2) 
				result.push_back(to_string(nums[i-1]+1) + "->" + to_string(nums[i]-1));
			else if (nums[i] == nums[i-1] + 2)
				result.push_back(to_string(nums[i-1]+1));
			i++;
		}
		i--;
		if (nums[i] + 1 < upper)
			result.push_back(to_string(nums[i]+1) + "->" + to_string(upper));
		else if (nums[i] + 1 == upper)
			result.push_back(to_string(nums[i]+1));
		return result;
	}
};

int main() {
	
	Solution sol;

	vector<int> v = {101};
	int lo = 1;
	int up = 100;

	auto vs = sol.findMissingRanges(v, lo, up);
	for (auto& s: vs)
		cout << s << endl;
}