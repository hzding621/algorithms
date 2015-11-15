class Solution {
public:
    int uniquePaths(int m, int n) {
        int p = max(m,n), q = min(m,n);
        vector<int> dp(q);
        for (int i=p-1; i>=0; i--) {
            for (int j=q-1; j>=0; j--) {
                if (i == p-1 && j == q-1) dp[j] = 1;
                else if (i == p-1) dp[j] = dp[j+1];
                else if (j == q-1) continue;
                else dp[j] = dp[j+1] + dp[j];
            }
        }
        return dp[0];
    }
};