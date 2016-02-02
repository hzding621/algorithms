class Solution {
public:
    int numSquares(int n) {
        vector<int> dp(n+1);
        for (int i=1; i<=n; i++) {
            int subMin = dp[i-1];
            int nearest = sqrt(i);
            for (int k = nearest; k > 1; k--) {
                subMin = min(subMin, dp[i-k*k]);
            }
            dp[i] = subMin + 1;
        }
        return dp[n];
    }
};