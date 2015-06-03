#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

class Solution {
public:
	int minSubArrayLen(int s, vector<int>& nums) {
		
		int i = 0, j = 0;
		int len = INT_MAX;
		int sum = 0;
		while (true) {
			while (sum < s && i < nums.size()) {
				sum += nums[i++];
			}
			
			if (sum < s && i == nums.size())
				break;

			len = min(len, i-j);
			
			do {
				sum -= nums[j++];
			} while (sum >= s);
			len = min(len, i-j+1);

			if ( i == nums.size())
				break;
		}
		return len == INT_MAX ? 0 : len;
	}
};

int main() {

	Solution s;

	vector<int> nums = {1,1,1,1,1,1};
	cout << s.minSubArrayLen(7, nums) << endl;
	return 0;
}