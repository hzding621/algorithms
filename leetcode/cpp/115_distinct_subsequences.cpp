#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
	int numDistinct(string s, string t) { 
		int m = s.length(), n = t.length();
		vector<vector<int>> dp;
		for (int i=0; i<=m; i++)
			dp.emplace_back(n+1);		
		for (int i=0; i<=m; i++) {
			dp[i][0] = 1;
		}
		for (int j=1; j<=n; j++) {
			dp[0][j] = 0;
		}
		for (int i=1; i<=m; i++) {
			for (int j=1; j<=n; j++) {
				dp[i][j] = dp[i-1][j];
				if (s[i-1] == t[j-1])
					dp[i][j] += dp[i-1][j-1];
			}
		}
		return dp[m][n];
	}
};

int main() {
	string s = "rabbbit";
	string t = "rabbit";
	Solution sol;
	cout << sol.numDistinct(s, t) << endl;
}