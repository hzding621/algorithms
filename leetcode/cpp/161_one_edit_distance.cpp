#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
#include <cmath>

using namespace std;

class Solution {
public:
	bool isOneEditDistance(string s, string t) {
		int m = s.length(), n = t.length();
		if (abs(m-n) > 1 || s == t)
			return false;
		int i = 0, j = 0;

		int foundDiff = false;
		while (i < m && j < n) {
			if (s[i] != t[j]) {
				if (foundDiff) return false;
				if (m >= n) i++;
				if (m <= n) j++;
				foundDiff = true;
			} else {
				i++;
				j++;
			}
		}
		return true;
	}
};

int main() {
	Solution sol;
	cout << sol.isOneEditDistance("ab", "ba") << endl;
}