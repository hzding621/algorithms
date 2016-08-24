#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

class Solution {
public:
    int getMoneyAmount(int n) {
        vector<vector<int>> dp;
        for (int i = 0; i < n+1; i++) {
            dp.emplace_back(n+1);
        }
        for (int len = 2; len <= n; len++) {
            for (int i = 1; i <= n && i + len - 1 <= n; i++) {
                int minCost = INT_MAX;
                for (int toCheck = i; toCheck <= i + len - 1; toCheck++) {
                    int cost = toCheck;
                    int leftCost = toCheck > i ? dp[i][toCheck-1] : 0;
                    int rightCost = toCheck < (i + len - 1) ? dp[toCheck+1][i+len-1] : 0;
                    cost += max(leftCost, rightCost);
                    minCost = min(minCost, cost);
                }
                dp[i][i+len-1] = minCost;
            }
        }
        return dp[1][n];
    }
};

int main() {

    Solution sol;
    cout << sol.getMoneyAmount(7) << endl;

    return 0;
}