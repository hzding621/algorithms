#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        if (nums.size() < 2)
            return nums.size();
        int endAsDown = 1, endAsUp = 1;
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] > nums[i - 1])
                endAsUp = endAsDown + 1;
            else if (nums[i] < nums[i - 1])
                endAsDown = endAsUp + 1;
        }
        return max(endAsDown, endAsUp);
    }
};

int main() {

    vector<int> v = {};

    Solution solution;

    cout << solution.wiggleMaxLength(v) << endl;

    return 0;
}