#include <iostream>
#include <string>
#include <vector>
#define N 1005

using namespace std;
int dp[N][N];
int longestPalindrome(string& s) {

	int n = s.size();
	if (n == 0) return 0;
	if (n == 1) return 1;
	for (int i=0; i<N; i++) {
		for (int j=0; j<N; j++)
			dp[i][j] = 1;
	}
	for (int len=2; len<=n; len++) {
		for (int i=0; i+len<=n; i++) {
			dp[i][i+len-1] = max(dp[i+1][i+len-1], dp[i][i+len-2]);
			if (s[i] == s[i+len-1])
				dp[i][i+len-1] = max(dp[i][i+len-1], (i + 1 > i+len-2 ? 0 : dp[i+1][i+len-2])+2);
		}
	}
	return dp[0][n-1];
}

int main() {
	
	int n;
	cin >> n;
	cin.ignore();
	for (int i=0; i<n; i++) {
		string s;
		getline(cin, s);
		int l = longestPalindrome(s);
		cout << l << endl;
	}
}