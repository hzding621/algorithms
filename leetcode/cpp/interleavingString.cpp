class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int m1=s1.length(), m2=s2.length(), n=s3.length();
        if (m1 + m2 != n) return false;
        if (m1 == 0) return s2 == s3;
        if (m2 == 0) return s1 == s3;
        vector<vector<int>> dp;
        for (int i=0; i<=m1; i++) dp.emplace_back(m2+1,false);
        
        // dp(i, j) = s3[i+j] == s1[i] && dp(i+1, j) || 
        //            s3[i+j] == s2[j] && dp(i, j+1)
        for (int i=m1; i>=0; i--) {
            for (int j=m2; j>=0; j--) {
                if (i==m1 && j==m2) dp[i][j] = true;
                else if (i==m1) dp[i][j] = s3[i+j] == s2[j] && dp[i][j+1];
                else if (j==m2) dp[i][j] = s3[i+j] == s1[i] && dp[i+1][j];
                else 
                    dp[i][j] = s3[i+j] == s1[i] && dp[i+1][j] || 
                               s3[i+j] == s2[j] && dp[i][j+1];
            }
        }
        return dp[0][0];
    }
};