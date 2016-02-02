#include <algorithm>
#include <vector>
#include <iostream>
#include <string>

using namespace std;

int minDistance(string word1, string word2) {

	int m = word1.length();
	int n = word2.length();
	vector<vector<int>> dp;
	for (int i=0; i<=m; i++) {
		dp.emplace_back(n+1);
	}
	for (int k = 0; k<=n; k++) {
		dp[0][k] = k;
	}
	for (int k = 0; k<=m; k++) {
		dp[k][0] = k;
	}
	for (int i = 1; i<=m; i++) {
		for (int j = 1; j<=n; j++) {
			dp[i][j] = min(1+dp[i-1][j], 1+dp[i][j-1]); // insert or delete
			dp[i][j] = min(dp[i][j], 1+dp[i-1][j-1]); // replace
			if (word1[i-1] == word2[j-1])
				dp[i][j] = min(dp[i][j], dp[i-1][j-1]);
		}
	}
	return dp[m][n];
}

int main() {
	
}