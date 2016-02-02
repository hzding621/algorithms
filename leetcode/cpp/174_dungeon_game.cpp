class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int m = dungeon.size(), n = dungeon[0].size();
        vector<vector<int>> dp;
        for (int i=0; i<m; i++)
            dp.emplace_back(n);
        dp[m-1][n-1] = max(1-dungeon[m-1][n-1], 1);
        for (int i=m-1; i>=0; i--) {
            for (int j=n-1; j>=0; j--) {
                if (i == m-1 && j == n-1)
                    continue;
                int next;
                if (i < m-1 && j < n-1)
                    next = min(dp[i+1][j],dp[i][j+1]);
                else if (i == m-1)
                    next = dp[i][j+1];
                else
                    next = dp[i+1][j];
                dp[i][j] = max(1, next-dungeon[i][j]);
            }
        }
        return dp[0][0];
    }
};

class SolutionLinearSpace {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int m = dungeon.size(), n = dungeon[0].size();
        vector<int> dp(n);
        dp[n-1] = max(1-dungeon[m-1][n-1], 1);
        for (int i=m-1; i>=0; i--) {
            for (int j=n-1; j>=0; j--) {
                if (i == m-1 && j == n-1)
                    continue;
                int next;
                if (i < m-1 && j < n-1)
                    next = min(dp[j],dp[j+1]);
                else if (i == m-1)
                    next = dp[j+1];
                else
                    next = dp[j];
                dp[j] = max(1, next-dungeon[i][j]);
            }
        }
        return dp[0];
    }
};