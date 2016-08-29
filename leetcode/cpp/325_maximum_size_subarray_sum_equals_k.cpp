#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
    int maxSubArrayLen(vector<int>& nums, int k) {
        if (nums.size() == 0) return 0;
        vector<int> prefixSum = {0};
        unordered_map<int, int> sumToFirstIndex;
        sumToFirstIndex[0] = -1;
        int best = nums[0] == k ? 1 : 0;
        for (int i = 0; i < nums.size(); i++) {
            int sum = prefixSum.back() + nums[i];
            prefixSum.push_back(sum);
            if (sumToFirstIndex.count(sum - k)) {
                best = max(best, i - sumToFirstIndex[sum-k]);
            }
            if (!sumToFirstIndex.count(sum)) {
                sumToFirstIndex[sum] = i;
            }
        }      
        return best;
    }
};

int main() {

    vector<int> v = {1, -1, 5, -2, 3};
    Solution sol;
    cout << sol.maxSubArrayLen(v, 1) << endl;

    return 0;
}