#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int summaryString(string A, string B, int op_cost){
	int m = A.length();
	int n = B.length();
	vector<vector<vector<int>>> dp;
	for (int i=0; i<=m; i++) {
		dp.emplace_back(n+1, vector<int>(6));
	}
	for (int j=0; j<n; j++) {
		dp[m][j][0]=dp[m][j][1]=dp[m][j][2]=dp[m][j][3]=n-j+op_cost;
		dp[m][j][3]--;
	}
	for (int i=0; i<m; i++) {
		dp[i][n][0]=dp[i][n][1]=dp[i][n][2]=dp[i][n][3]=m-i+op_cost;
		dp[i][n][1]--;
	}
	for (int i=m-1;i>=0;i--) {
		for (int j=n-1;j>=0;j--) {
			// op is empty
			dp[i][j][0] = min(dp[i+1][j][1],dp[i][j+1][3])+op_cost+1;
			if (A[i]==B[j])
				dp[i][j][0] = min(dp[i][j][0],dp[i+1][j+1][2]+op_cost+1);

			// op is 1
			dp[i][j][1] = min(dp[i+1][j][1]+1,dp[i][j][0]);
			// op is 2
			dp[i][j][2] = dp[i][j][0];
			if (A[i]==B[j])
				dp[i][j][2] = min(dp[i][j][2], dp[i+1][j+1][2]+1);
			// op is 3
			dp[i][j][3] = min(dp[i][j+1][3]+1,dp[i][j][0]);
		}
	}
	return dp[0][0][0];
}

int main() {
	string A = "kitten";
	string B = "knitting";
	int op_cost = 0;
	cout << summaryString(A, B, op_cost) << endl;
	return 0;
}