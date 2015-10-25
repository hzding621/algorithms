#include <iostream>
#include <string>
#include <vector>

using namespace std;

void generateParenthesisRec(vector<string>& result, string prefix, int openPr, int closePr) {
	cout << openPr << " " << closePr << endl;
	if (openPr > 0)
		generateParenthesisRec(result, prefix + "(", openPr-1, closePr+1);
	if (closePr > 0)
		generateParenthesisRec(result, prefix + ")", openPr, closePr-1);
	if (openPr == 0 && closePr == 0)
		result.push_back(prefix);
}

vector<string> generateParenthesis(int n) {
	vector<string> result;
	generateParenthesisRec(result, "", n, 0);
	return result;
}

vector<string> generateParenthesisDP(int n) {
	vector<vector<string>> dp(n+1);
	// dp(i, j) = { dp[i+1, j-1] + '(', 
	//				dp[i, j+1] + ')'
	// 
	dp[0].push_back("");
	for (int i=n-1; i>=0; i--) {
		for (int j=n; j>=0; j--) {
			if (i + j>n)
				continue;
			dp[j].clear();
			if (j < n) {
				auto v = dp[j+1];
				for (auto& s: v) {
					s += ')';
					dp[j].push_back(s);
				}
			}
			if (j > 0) {
				auto v = dp[j-1];
				for (auto& s: v) {
					s += '(';
					dp[j].push_back(s);
				}
			}
		}
	}
	return dp[0];
}

int main() {
	for (int i=0; i<=4; i++) {
		cout << endl << "n=" << i << endl;	
		auto vs = generateParenthesisDP(i);
		for (auto s: vs)
			cout << s << endl;

	}

}