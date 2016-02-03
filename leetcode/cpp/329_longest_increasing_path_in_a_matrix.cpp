#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
	int dfs(vector<vector<int>>& matrix, vector<vector<int>>& memoize, int i, int j, int m, int n) {
		if (memoize[i][j] == -1) {
			int maxlen = 1;
			if (i < m-1 && matrix[i+1][j] > matrix[i][j])
				maxlen = max(maxlen, 1 + dfs(matrix, memoize, i+1, j, m, n));
			if (j < n-1 && matrix[i][j+1] > matrix[i][j])
				maxlen = max(maxlen, 1 + dfs(matrix, memoize, i, j+1, m, n));
			if (i > 0 && matrix[i-1][j] > matrix[i][j])
				maxlen = max(maxlen, 1 + dfs(matrix, memoize, i-1, j, m, n));
			if (j > 0 && matrix[i][j-1] > matrix[i][j])
				maxlen = max(maxlen, 1 + dfs(matrix, memoize, i, j-1, m, n));
			memoize[i][j] = maxlen;
		}
		return memoize[i][j];
	}
public:
	int longestIncreasingPath(vector<vector<int>>& matrix) {
		int m = matrix.size();
		if (m == 0) return 0;
		int n = matrix[0].size();
		if (n == 0) return 0;
		vector<vector<int>> memoize;
		for (int i=0; i<m; i++)
			memoize.emplace_back(n, -1);
		int maxlen = 1;
		for (int i=0; i<m; i++) {
			for (int j=0; j<n; j++) {
				maxlen = max(maxlen, dfs(matrix, memoize, i, j, m, n));
			}
		}
		return maxlen;
	}
};

int main() {
	vector<vector<int>> vv;
	vv.push_back(vector<int>{3,4,5});
	vv.push_back(vector<int>{3,2,6});
	vv.push_back(vector<int>{2,2,1});

	Solution sol;
	cout << sol.longestIncreasingPath(vv) << endl;
}