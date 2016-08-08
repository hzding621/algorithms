#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<string> removeInvalidParentheses(string s) {
    	vector<string> answer;
    	search(answer, s, 0, 0, '(', ')');
    	return answer;
    }
private:
	void search(vector<string>& answer, string s, int scanStart, int removeStart, char openParen, char closeParen) {
		// cout << "test: " << s << endl;
		int stack = 0, i = scanStart;
		for (; i < s.length(); i++) {
			if (s[i] == openParen) stack++;
			if (s[i] == closeParen) stack--;
			if (stack < 0)
				break;
		}
		if (stack < 0) {
			for (int j = removeStart; j <= i; j++) {
				if (s[j] == closeParen && (j == removeStart || s[j-1] != closeParen)) {
					string substr = s.substr(0, j) + s.substr(j+1);
					// s is one character shorter
					search(answer, substr, i, j, openParen, closeParen);
				}
			}
		} else {
			reverse(s.begin(), s.end());
			if (openParen == '(') {
				search(answer, s, 0, 0, ')', '(');
			} else {
				answer.push_back(s);
			}
		}
	}
};

vector<string> testCases = {
	"()())()"
   ,"(a)())()"
   ,")("
   ,""
   ,"))(p(((())"
};

int main() {
	Solution sol;
	for (auto& t: testCases) {
		auto vs = sol.removeInvalidParentheses(t);
		for (string& s: vs) {
			cout << s << endl;
		}
		cout <<  "######" << endl;
	}
}