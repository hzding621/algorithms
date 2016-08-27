#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        if (n == 0) {
            return {};
        }
        vector<int> longestEndAt(n);
        vector<int> parentOfLongestEndAt(n);
        // longestEndAt[i] = longest subsequence ending at i
        // parentOfLongestEndAt = previous index in the longest subsequence ending at i (parent pointer)

        for (int i = 0; i < n; i++) {
            longestEndAt[i] = 1;
            parentOfLongestEndAt[i] = -1;
            for (int j = 0; j < i; j++) {
                if (nums[i] % nums[j] == 0 && 1 + longestEndAt[j] > longestEndAt[i]) {
                    longestEndAt[i] = 1 + longestEndAt[j];
                    parentOfLongestEndAt[i] = j;
                }
            }
        }

        // find best
        int bestEnd = 0;
        for (int i = 1; i < n; i++) {
            if (longestEndAt[i] >= longestEndAt[bestEnd]) {
                bestEnd = i;
            }
        }

        vector<int> result;
        while (bestEnd != -1) {
            result.push_back(nums[bestEnd]);
            bestEnd = parentOfLongestEndAt[bestEnd];
        }
        reverse(result.begin(), result.end());

        return result;
    }
};

int main() {

    Solution sol;
    vector<int> v = {2,3,4,5,6,7,8,9,18,24};
    vector<int> vi = sol.largestDivisibleSubset(v);
    for (int i: vi) {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}