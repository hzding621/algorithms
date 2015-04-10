#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using std::string;
using std::vector;
using std::cout;
using std::endl;
using std::min;

int palindrome_decomp(string& s) {
	int n = s.length();
	if (n == 0)
		return 0;

	bool** isPal = new bool*[n];
	for (int x=0; x<n; x++)
		isPal[x] = new bool[n];

	for (int i=n-1; i>=0; i--) {
		for (int j=0; j<n; j++) {
			if (i > j)
				isPal[i][j] = true;
			else {
				bool dp;
				if (i+1>=n)
					dp = true;
				else if (j-1<0)
					dp = true;
				else
					dp = isPal[i+1][j-1];
				isPal[i][j] = s[i]==s[j] && dp;
			}
		}
	}

	int* minPal = new int[n];
	minPal[0] = 1;
	for (int i=1; i<n; i++) {
		int m = i+1;
		for (int j=0; j<=i; j++) {
			if (isPal[j][i]) {
				m = min(m, j > 0 ? 1+minPal[j-1] : 1);
			}
		}
		minPal[i] = m;
	}
	return minPal[n-1];
}

int main() {

	vector<string> tests;
	tests.push_back("ASCII");
	for (string& s: tests)
		cout << s << ":" << palindrome_decomp(s) << endl;

	return 0;
}