#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.size() == 0)
        	return "";
        return recurse(strs, 0);
    }

private:

	string recurse(vector<string>& strs, int startIndex) {
		if (strs[0].length() <= startIndex)
        	return "";
        char c = strs[0][startIndex];
        for (int i = 1; i < strs.size(); i++) {
        	if ((strs[i].length() <= startIndex) || (strs[i][startIndex] != c)) {
        		return "";
        	}
        }
        return c + recurse(strs, startIndex+1);
	}
};

int main() {

	vector<string> vs = {"123","12", "12"};
	Solution sol;
	cout << sol.longestCommonPrefix(vs) << endl;

	return 0;
}