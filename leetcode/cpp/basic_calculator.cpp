#include <iostream>
#include <string>
#include <stack>
#include <stdexcept>

using namespace std;

class Solution {
public:
    int calculate(string s) {
        int total_value = 0;
        stack<int> prev_value;
        stack<char> prev_op;
        int cur_value = 0;
        char cur_op = '+';
        s.push_back('+');
        for (int i=0; i<s.length(); i++) {
            char c = s[i];
            if (c == ' ')
                continue;
            else if (c >= '0' && c <= '9')
                cur_value = cur_value * 10 + (c - '0');
            else if (c == '+' || c == '-') {
                total_value = cur_op == '+' ? (total_value + cur_value) : (total_value - cur_value);
                cur_value = 0;
                cur_op = c;
            } else if (c == '(') {
                if (cur_value != 0)
                    throw runtime_error("number followed by (");
                prev_value.push(total_value);
                prev_op.push(cur_op);
                total_value = 0;
                cur_op = '+';
            } else if (c == ')') {
                total_value = cur_op == '+' ? (total_value + cur_value) : (total_value - cur_value);
                int pv = prev_value.top();
                char po = prev_op.top();
                cur_value = total_value;
                total_value = pv;
                cur_op = po;
                prev_value.pop();
                prev_op.pop();
            } else {
                string s = "unsupport character ";
                s += c;
                throw runtime_error(s);
            }
        }
        return total_value;
    }
};

int main() {

    Solution sol;
    cout << sol.calculate("(1+(4+5+2)-3)+(6+8)") << endl;

    return 0;
}
