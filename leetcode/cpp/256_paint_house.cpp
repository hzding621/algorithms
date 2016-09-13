#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int minCost(vector<vector<int>>& costs) {
        // Same As Paint House II

        // dp[i][j][0] = optCost painting up to house i, with house i having color j
        //     = dp[i-1][j][1] + cost[i][j]
        // dp[i][j][1] = optCost painting up to house i, with house i not having color j
        //     = havingJIsOptimal ? secondBestValue : firstBestValue;

        int n = costs.size();
        if (n == 0) return 0;
        int k = costs[0].size();
        if (k == 0) return 0;
        vector<vector<int>> dpWithColor;
        vector<vector<int>> dpWithoutColor;
        for (int i = 0; i < n; i++) {
            dpWithColor.emplace_back(k);
            dpWithoutColor.emplace_back(k);
        }
        int firstBest, secondBest;

        for (int i = 0; i < n; i++) {
            firstBest = secondBest = INT_MAX;
            for (int j = 0; j < k; j++) {
                if (i == 0) {
                    dpWithColor[i][j] = costs[i][j];
                } else {
                    dpWithColor[i][j] = dpWithoutColor[i-1][j] + costs[i][j];
                }
                if (dpWithColor[i][j] < firstBest) {
                    secondBest = firstBest;
                    firstBest = dpWithColor[i][j];
                } else {
                    secondBest = min(secondBest, dpWithColor[i][j]);
                }
            }
            for (int j = 0; j < k; j++) {
                dpWithoutColor[i][j] = dpWithColor[i][j] == firstBest ? secondBest : firstBest;
            }
        }

        int best = INT_MAX;
        for (int j = 0; j < k; j++) {
            best = min(best, dpWithColor.back()[j]);
        }
        return best;
    }
};

int main() {

    vector<vector<int>> costs = {
            {4,16},{15,5},{18,17},{10,12},{14,10},{3,10},{2,11},{18,14},{9,1},{14,13}
    };

    Solution sol;
    cout << sol.minCostII(costs) << endl;

    return 0;
}