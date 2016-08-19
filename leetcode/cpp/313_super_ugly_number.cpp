#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <climits>

using namespace std;

class Solution {
public:
	int nthSuperUglyNumber(int n, vector<int>& primes) {
		vector<int> uglyNumbers(n);
		vector<int> nextIndexToMultiplyList(primes.size());
		uglyNumbers[0] = 1;
		for (int i = 1; i < n; i++) {
			uglyNumbers[i] = INT_MAX;
			for (int j = 0; j < primes.size(); j++) {
				if (uglyNumbers[i-1] == uglyNumbers[nextIndexToMultiplyList[j]] * primes[j]) {
					// dedup
					nextIndexToMultiplyList[j]++;
				}
				uglyNumbers[i] = min(uglyNumbers[i], uglyNumbers[nextIndexToMultiplyList[j]] * primes[j]);
			}
		}
		return uglyNumbers.back();
	}
};

int main() {

	Solution sol;
	vector<int> v = {2, 7, 13, 19};
	cout << sol.nthSuperUglyNumber(12, v) << endl;

	return 0;
}
