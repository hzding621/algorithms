#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int i = nums.size() - 1;
        while (i > 0 && nums[i-1] >= nums[i]) {
            i--;
        }
        if (i > 0) {
            // find smallest number greater than nums[i-1]
            int j = nums.size() - 1;
            while (j >= i) {
                if (nums[j] > nums[i-1]) break;
                j--;
            }
            int t = nums[j];
            nums[j] = nums[i-1];
            nums[i-1] = t;
        }
        reverse(nums.begin() + i, nums.end());
    }
};
int main() {

    vector<int> v = {1,2,3};
    Solution solution;
    for (int i = 0; i < 6; i++) {
        solution.nextPermutation(v);
        for (int n: v) {
            cout << n << " ";
        }
        cout << endl;
    }

}