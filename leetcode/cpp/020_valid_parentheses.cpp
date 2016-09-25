#include <iostream>
#include <stack>

using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char> openParentheses;
        for (char c: s) {
            if (c == '(' || c == '{' || c == '[') {
                openParentheses.push(c);
            } else {
                if (openParentheses.empty()) return false;
                if (c == ')' && openParentheses.top() != '(')
                    return false;
                if (c == ']' && openParentheses.top() != '[')
                    return false;
                if (c == '}' && openParentheses.top() != '{')
                    return false;
                openParentheses.pop();
            }
        }
        return openParentheses.empty();
    }
};

int main() {

    Solution solution;
    cout << solution.isValid("()") << endl;
    cout << solution.isValid("()[]{}") << endl;
    cout << solution.isValid("(]") << endl;
    cout << solution.isValid("([)]") << endl;
}