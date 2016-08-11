#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cstdlib>

using namespace std;

class Solution {
public:
    bool isAdditiveNumber(string num) {
        for (int i = 0; i < num.size(); i++) {
        	string firstNum = num.substr(0, i+1);
        	if (firstNum[0] == '0' && firstNum.size() > 1)
        		break;
        	long firstNumInt = stol(firstNum);
        	if (firstNumInt > INT_MAX)
        		break;
        	for (int j = i + 1; j < num.size(); j++) {
        		string secondNum = num.substr(i+1, j-i);
        		if (secondNum[0] == '0' && secondNum.size() > 1)
        			break;
        		long secondNumInt = stol(secondNum);
        		if (secondNumInt > INT_MAX)
        			break;
        		if (search(firstNumInt, secondNumInt, num, j+1))
        			return true;
        	}
        }
        return false;
    }
private:
	bool search(long firstNumInt, long secondNumInt, string& num, int startIndex) {
		long numberToSearch = firstNumInt + secondNumInt;
		string s = to_string(firstNumInt + secondNumInt);
		int i = 0, j = startIndex;
		while (i < s.size() && j < num.size()) {
			if (s[i] != num[j])
				return false;
			i++;
			j++;
		}
		if (i < s.size()) return false;
		if (j == num.size()) return true;
		return search(secondNumInt, numberToSearch, num, j);
	}
};

int main() {

	Solution sol;

	// string s = "198019823962";
	string s = "11235813213455890144";
	cout << sol.isAdditiveNumber(s) << endl;
}