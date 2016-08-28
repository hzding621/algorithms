#include <algorithm>
#include <climits>
#include <iostream>
#include <set>
#include <vector>

using namespace std;

class Solution {
public:
    int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
        int n = matrix.size(); 
        if (n == 0) return 0;
        int m = matrix[0].size();
        if (m == 0) return 0;

        int best = INT_MIN;
        for (int i = 0; i < m; i++) {
            vector<int> sumFromIToJ(n);
            for (int j = i; j < m; j++) {
                // for each i, j pair, i <= j, take sum from column i to column j
                for (int r = 0; r < n; r++) {
                    sumFromIToJ[r] += matrix[r][j];
                }
                int localBest = maximumSumArrayAtMostK(sumFromIToJ, k);
                best = max(best, localBest);
            }
        }
        return best;
    }

private:

    int maximumSumArrayAtMostK(vector<int>& array, int k) {
        set<int> prefixSums = {0};
        int curPrefixSum = 0, currentBestSubSum = INT_MIN;
        for (int i = 0; i < array.size(); i++) {
            curPrefixSum += array[i];
            
            // find the smallest prefix sum It such that curPrefixSum - It <= k
            auto it = prefixSums.lower_bound(curPrefixSum - k); 
            if (it != prefixSums.end()) {
                currentBestSubSum = max(currentBestSubSum, curPrefixSum - *it);
            }
            // subarray must be non-empty
            prefixSums.insert(curPrefixSum);
        }
        return currentBestSubSum;
    }
};

int main() {

    vector<vector<int>> vv = {
        {2, 2, -1},
        // { 0,  6,  3,  4, 1},
        // { 2, -2, -1,  4,-5},
        // {-3,  3,  1,  0, 3}
    };
    Solution sol;
    cout << sol.maxSumSubmatrix(vv, 0) << endl;

    return 0;
}