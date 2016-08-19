#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) {
            return 0;
        } else if (n == 1) {
            return nums[0];
        } else if (n == 2) {
            return max(nums[0], nums[1]);
        }

        vector<int> dpCanRobLast(n);
        dpCanRobLast[n-1] = nums[n-1];
        applyDP(dpCanRobLast, n, nums);
        dpCanRobLast[0] = dpCanRobLast[1];

        vector<int> dpCannotRobLast(n);
        dpCannotRobLast[n-1] = 0;
        applyDP(dpCannotRobLast, n, nums);
        dpCannotRobLast[0] = max(dpCannotRobLast[1], dpCannotRobLast[2] + nums[0]);

        return max(dpCanRobLast[0], dpCannotRobLast[0]);
    }

private:
    void applyDP(vector<int>& dpMemoize, int n, vector<int>& values) {
        for (int i = n-2; i > 0; i--) {
            dpMemoize[i] = max(dpMemoize[i+1], (i < n-2 ? dpMemoize[i+2] : 0) + values[i]);
        }
    }
};

int main() {

    return 0;
}