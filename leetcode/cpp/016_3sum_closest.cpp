#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int difference = INT_MAX;
        int candidate = INT_MAX;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); i++) {
            int j = i + 1, k = nums.size() - 1;
            while (j < k) {
                int sum = nums[i] + nums[j] + nums[k];
                if (abs(sum - target) < difference) {
                    difference = abs(sum -  target);
                    candidate = sum;
                }
                if (sum <= target) {
                    j++;
                } else {
                    k--;
                }
            }
        }
        return candidate;
    }
};

int main() {
    vector<int> v = {-1, 2, 1, -4};
    int target = 1;
    Solution solution;
    cout << solution.threeSumClosest(v, target) << endl;
}