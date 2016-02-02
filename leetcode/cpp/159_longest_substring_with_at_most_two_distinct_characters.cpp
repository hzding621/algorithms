#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
	int lengthOfLongestSubstringTwoDistinct(string s) {
		int n = s.length();
		if (n <= 1) return n;
		char c1 = s[0], c2;
		int i1 = 0, i2, i = 1, j = 0;
		while (i < n && s[i] == c1) {
			i++;
		}
		if (i == n) return n;
		c2 = s[i];
		i2 = i;
		int maxlen = i+1;
		i++;
		while (i < n) {
			if (s[i] != c1 && s[i] != c2) {
				if (i1 < i2) {
					i1 = i2;
					c1 = c2;
				}
				maxlen = max(maxlen, i-j);
				j = i1;
				i2 = i;
				c2 = s[i];
			} else if (s[i] == c1) {
				if (s[i-1] != c1) {
					i1 = i;
				}
			} else {
				if (s[i-1] != c2) {
					i2 = i;
				}
			}
			i++;
		}
		maxlen = max(maxlen, i-j);
		return maxlen;
	}
};

int main() {

	Solution sol;

	vector<string> ss = {
		"aabbccc",
		"abaccc"
	};
	for (string& s: ss)
		cout << sol.lengthOfLongestSubstringTwoDistinct(s) << endl;
}