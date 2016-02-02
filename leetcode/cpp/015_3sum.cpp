// https://leetcode.com/problems/3sum/

// Given an array S of n integers, are there elements a, b, c in S such that a + b + c = 0? Find all unique triplets in the array which gives the sum of zero.

// Note:
// Elements in a triplet (a,b,c) must be in non-descending order. (ie, a ≤ b ≤ c)
// The solution set must not contain duplicate triplets.
//     For example, given array S = {-1 0 1 2 -1 -4},

//     A solution set is:
//     (-1, 0, 1)
//     (-1, -1, 2)

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
	vector<vector<int>> threeSum(vector<int>& nums) {
		int n = nums.size();
		if (n < 3) return {};
		sort(nums.begin(), nums.end());
		vector<vector<int>> ans;
		for (int i=0; i<n-2; i++) {
			if (i > 0 && nums[i] == nums[i-1]) continue;
			int sumTo = -nums[i];
			int j = i+1, k = n-1;
			while (j < k) {
				int s = nums[j] + nums[k];
				if (s == sumTo) {
					ans.push_back(vector<int>{nums[i],nums[j],nums[k]});
					do { j++; }
					while ( j < k && nums[j]==nums[j-1]);
				}
				else if (s < sumTo) 
					j++;
				else
					k--;
			}
		}
		return ans;
	}
};

void print(const vector<vector<int>>& vv) {
	for (const auto& v: vv) {
		for (int i: v)
			cout << i << " ";
		cout << endl;
	}
}

int main() {

	Solution sol;
	vector<int> v = {-1,0,1,2,-1,-4};
	auto ans = sol.threeSum(v);
	print(ans);
	return 0;
}
