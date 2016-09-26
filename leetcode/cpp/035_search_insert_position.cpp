#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        return first_not_less_than(nums, 0, nums.size() - 1, target);
    }
private:
    int first_not_less_than(vector<int> &nums, int i, int j, int target) {
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
};

int main() {

    vector<pair<vector<int>, int>> testCases = {
            {{1,3,5,6}, 5},
            {{1,3,5,6}, 2},
            {{1,3,5,6}, 7},
            {{1,3,5,6}, 0}
    };
    Solution solution;
    for (auto& p: testCases) {
        cout << solution.searchInsert(p.first, p.second) << endl;
    }

}