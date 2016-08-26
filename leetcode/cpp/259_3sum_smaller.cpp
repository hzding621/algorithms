#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int threeSumSmaller(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int count = 0;
        for (int k = 2; k < nums.size(); k++) {
            int i = 0, j = k - 1;
            int sumTarget = target - nums[k]; // we want nums[i] + nums[j] < sumTarget
            while (i < j) {
                if (nums[i] + nums[j] < sumTarget) {
                    count += (j - i);
                    i++;
                } else {
                    j--;
                }
            }
        }
        return count;
    }
};

int main() {

    vector<int> nums = {-2, 2, 1, 6};
    int target = 5;
    Solution sol;
    cout << sol.threeSumSmaller(nums, target) << endl;

    return 0;
}