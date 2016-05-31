#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <utility>

using namespace std;


int longestMonotoneSubarray(vector<int>& v) {
	int n = v.size();
	if (n == 1) return 1;
	int previousLength = 2, previousDiff = v[1] - v[0];
	int maxLength = 2;
	for (int i=2; i<n; i++) {
		int d = v[i]-v[i-1];
		previousLength = d == previousDiff ? previousLength + 1 : 2;
		previousDiff  = d;
		maxLength = max(maxLength, previousLength);
	}
	return maxLength;

}

int longestMonotoneSubsequence(vector<int>& v) {
	int n = v.size();
	if (n == 1) return 1;
	vector<vector<int>> length;
	for (int i=0; i<n; i++) {
		length.emplace_back(n);
	}
	vector<unordered_map<int, vector<int>>> previousIndices(n);
	length[0][1] = 2;
	previousIndices[1][v[1]-v[0]].push_back(0);
	int maxLength = 2;
	for (int j=2; j<n; j++) {
		for (int i=0; i<=j-1; i++) {
			previousIndices[j][v[j]-v[i]].push_back(i);
		}
		length[0][j]=2;
		int maxLengthi = 2;
		for (int i=1; i<=j-1; i++) {
			int d = v[j]-v[i];
			length[i][j] = 2;
			for (int k: previousIndices[i][d]) {
				length[i][j] = max(length[i][j], 1 + length[k][i]);
			}
			maxLengthi = max(maxLengthi, length[i][j]);
		}
		maxLength = max(maxLength, maxLengthi);
	}
	return maxLength;
}

int main() {
	vector<int> v = {1,2,6,3,7,4,8,5,7,6,8,7,8};
	cout << longestMonotoneSubsequence(v) << endl;
	return 0;
}