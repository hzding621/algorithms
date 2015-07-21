#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    bool isMatch(string s, string p) {
        vector<vector<bool>> dp;
        int m = s.length(), n = p.length();
        for (int i=0; i<=m; i++)
            dp.emplace_back(n+1);
        dp[m][n] = true;
        int i = n-1;
        while (i >= 0 && p[i] == '*')
            dp[m][i--] = true;
        while (i >= 0)
            dp[m][i--] = false;
        i = m-1;
        while (i >= 0 && s[i] == '*')
            dp[i--][n] = true;
        while (i >= 0)
            dp[i--][n] = false;
        for (int i=m-1; i>=0; i--) {
            for (int j=n-1; j>=0; j--) {
                char c = s[i], d = p[j];
                if (d == '*')
                    dp[i][j] = dp[i+1][j] || dp[i][j+1];
                else
                    dp[i][j] = dp[i+1][j+1] && (d == '?' || c == d);
            }
        }
        return dp[0][0];
    }
};

int main() {

    Solution sol;
    cout << boolalpha;
    cout << sol.isMatch("aa","a") << " " << false << endl;
    cout << sol.isMatch("aa","aa") << " " << true << endl;
    cout << sol.isMatch("aaa","aa") << " " << false << endl;
    cout << sol.isMatch("aa", "*") << " " << true << endl;
    cout << sol.isMatch("aa", "a*") << " " << true << endl;
    cout << sol.isMatch("ab", "?*") << " " << true << endl;
    cout << sol.isMatch("aab", "c*a*b") << " " << false << endl;

    return 0;
}
