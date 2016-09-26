#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int lb = first_not_less_than(nums, 0, nums.size() - 1, target);
        int ub = first_greater_than(nums, 0, nums.size() - 1, target);
        if (lb == ub) return {-1, -1};
        else return {lb, ub - 1};
    }
private:
    int first_not_less_than(vector<int>& nums, int i, int j, int target) {
         if (i == j) {
             return nums[i] >= target ? i : i+1;
         } else if (i + 1 == j) {
             return nums[i] >= target ? i : first_not_less_than(nums, j, j, target);
         } else {
             int m = (i + j) / 2;
             if (nums[m] < target) {
                 return first_not_less_than(nums, m + 1, j, target);
             } else if (nums[m] == target) {
                 return first_not_less_than(nums, i, m, target);
             } else {
                 return first_not_less_than(nums, i, m - 1, target);
             }
         }
     }

    int first_greater_than(vector<int>& nums, int i, int j, int target) {
        if (i == j) {
            return nums[i] > target ? i : i + 1;
        } else if (i + 1 == j) {
            return nums[i] > target ? i : first_greater_than(nums, j, j, target);
        } else {
            int m = (i + j) / 2;
            if (nums[m] <= target) {
                return first_greater_than(nums, m + 1, j, target);
            } else {
                return first_greater_than(nums, i, m, target);
            }
        }
    }
};

int main() {

    vector<int> v = {1,3,3,4,4,5};
    Solution solution;
    auto vi = solution.searchRange(v, 1);
    cout << vi[0] << "," << vi[1] << endl;
}