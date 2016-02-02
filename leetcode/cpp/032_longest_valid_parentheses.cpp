#include <iostream>
#include <string>
#include <stack>

using namespace std;

class Solution {
	public:
		int longestValidParentheses(string s) {
			
			stack<char> chars;
			stack<size_t> pos;
			chars.push('*');
			pos.push(-1);
			for (size_t i=0; i<s.length(); i++) {
				if ( s[i] == ')'&& ( chars.top() == '(')) {
					chars.pop();
					pos.pop();
				} else {
					chars.push(s[i]);
					pos.push(i);
				}
			}
			chars.push('*');;
			pos.push(s.length());
			
			int maxLen = 0;
			while (pos.size()>1) {
				int p = pos.top();					
				pos.pop();
				int len = p - pos.top() - 1;
				maxLen = max(maxLen, len);
			}
			return maxLen;
		}
};

int main() {
	
	Solution s;
	string strs[] = {
		")()())",
		"(()())",
		")((()))("
	};
	for (string str : strs) {
		cout << s.longestValidParentheses(str) << endl;
	}
	return 0;
}

