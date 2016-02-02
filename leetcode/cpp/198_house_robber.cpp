#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int rob(vector<int> &num) {
	int n = num.size();
	if (n == 0)
		return 0;
	if (n == 1)
		return max(0, num[0]);
	if (n == 2)
		return max(0, max(num[0], num[1]));
	vector<int> dp(n,0);
	dp[n-1] = max(0, num[n-1]);
	dp[n-2] = max(num[n-2], dp[n-1]);
	for (int i=n-3; i>=0; i--) {
		dp[i] = max(num[i]+dp[i+2], dp[i+1]);
	}
	return dp[0];
}

int main() {

	vector<int> num =  {1,2,3,4,5}; // ans = 9
	cout << rob(num) << endl;

	return 0;
}