#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <stdexcept>

using namespace std;

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> eval;
        for (int i=0; i<tokens.size(); i++) {
            string s = tokens[i];
            int v;
            try {
                v = stoi(s);
            } catch ( const invalid_argument& e) {

                int rhs = eval.top();
                eval.pop();
                int lhs = eval.top();
                eval.pop();

                if (s == "+") {
                    v = lhs + rhs;
                } else if (s == "-") {
                    v = lhs - rhs;
                } else if (s == "*") {
                    v = lhs * rhs;
                } else {
                    v = lhs / rhs;
                }
            }
            eval.push(v);
        }
        return eval.top();
    }
};

int main() {

    Solution sol;
    vector<string> v1 = {"2", "1", "+", "3", "*"};
    vector<string> v2 = {"4", "13", "5", "/", "+"};
    cout << sol.evalRPN(v1) << endl;
    cout << sol.evalRPN(v2) << endl;
}