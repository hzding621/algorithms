#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        for (int i = 1; i < nums.size(); i++) {
            if (i % 2) {
                if (nums[i] < nums[i-1]) {
                    iter_swap(nums.begin() + i, nums.begin() + i - 1);
                }
            } else {
                if (nums[i] > nums[i-1]) {
                    iter_swap(nums.begin() + i, nums.begin() + i - 1);
                }
            }
        }      
    }
};

int main() {

    vector<int> v = {3, 5, 2, 1, 6, 4};
    Solution sol;
    sol.wiggleSort(v);
    for (int i : v) {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}