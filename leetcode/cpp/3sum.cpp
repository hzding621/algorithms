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
