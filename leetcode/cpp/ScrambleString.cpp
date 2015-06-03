#include <string>
#include <iostream>

using namespace std;

class Solution {
public:
	bool isScramble(string s1, string s2) {
		
		if (s1.length() != s2.length())
			return false;
		int n = s1.length();
		bool dp[n][n][n];
		memset(dp, 0, n*n*n);

		for (int i=0; i<n; i++)
			for (int j=0; j<n; j++)
				dp[0][i][j] = s1[i] == s2[j];
		for (int len=2; len<=n; len++) {
			for (int s=0; s+len-1<n; s++){
				for (int t=0; t+len-1<n; t++) {
					bool p = false;
					for (int j=1; j<len; j++) {
						p = p || (dp[j-1][s][t] && dp[len-j-1][s+j][t+j]);
						p = p || (dp[j-1][s][t+len-j] && dp[len-j-1][s+j][t]);
						if (p) 
							break;
					}
					dp[len-1][s][t] = p;
				}
			}
		}
		return dp[n-1][0][0];
	}
};

int main() {

	Solution s;
	cout << boolalpha << s.isScramble("great", "rgtae") << endl;

	return 0;
}

