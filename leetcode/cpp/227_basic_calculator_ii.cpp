#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
	int calculate(string s) {
        int result = 0;
        int operand = 0;
        char lastOperator = '+';
        char stackedOperator = '+';
        int stackedResult = 0;
        s.push_back('+');
        for (int i=0; i<s.length(); i++) {
            char c = s[i];
            if (c == ' ')
                continue;
            else if (c == '+' || c == '-') {
                if (lastOperator == '*')
                    stackedResult *= operand;
                else if (lastOperator == '/')
                    stackedResult /= operand;
                else if (lastOperator == '+')
                    result += operand;
                else
                    result -= operand;
                if (lastOperator == '*' || lastOperator == '/') {
                    if (stackedOperator == '+')
                        result += stackedResult;
                    else if (stackedOperator == '-')
                        result -= stackedResult;
                }
                stackedResult = 0;
                operand = 0;
                lastOperator = c;
                stackedOperator = c;
            } else if (c == '*' || c == '/') {
                if (lastOperator == '*')
                    stackedResult *= operand;
                else if (lastOperator == '/')
                    stackedResult /= operand;
                else {
                    stackedResult = operand;
                }
                operand = 0;
                lastOperator = c;
            } else {
                operand = operand * 10 + ( c - '0');
            }
        }
        return result;
    }
};

int main() {

	Solution sol;
	cout << sol.calculate("1+2*3-4") << endl;
	return 0;
}
