class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size(); 
        if (m == 0) return 0;
        int n = obstacleGrid[0].size();
        if (n == 0) return 0;
        bool s = false;
        if (m < n) {
            swap(m,n);
            s = true;
        }
        vector<int> dp(n);
        for (int i=m-1; i>=0; i--) {
            for (int j=n-1; j>=0; j--) {
                if (s && obstacleGrid[j][i]) dp[j] = 0;
                else if (!s && obstacleGrid[i][j]) dp[j] = 0;
                else if (i == m-1 && j == n-1) dp[j] = 1;
                else if (i == m-1) dp[j] = dp[j+1];
                else if (j == n-1) continue;
                else 
                    dp[j] = dp[j] + dp[j+1];
            }
        }
        return dp[0];
    }
};