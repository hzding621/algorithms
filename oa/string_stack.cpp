#include <iostream>
#include <stack>
#include <string>
#include <climits>

using std::stack;
using std::string;
using std::cout;
using std::endl;

bool overflow(unsigned int a, unsigned int b, bool is_plus) {
    unsigned int s;
    if (is_plus) {
        s = a + b;
    } else {
        s = a * b;
    }
    return s > 4096;
}

int solution(string &S) {
    // write your code in C++11
    stack<unsigned int> stack; 
    for (int i=0; i<S.length(); i++) {
        char c = S[i];
        if (c >= '0' && c <= '9')
            stack.push(c-'0');
        else {
            unsigned int a, b;
            if (stack.empty())
                return -1;
            else {
                a = stack.top();
                stack.pop();
            }
            if (stack.empty())
                return -1;
            else {
                b = stack.top();
                stack.pop();
            }
            bool is_plus = c == '+';
            if (overflow(a,b,is_plus))
                return -1;
            unsigned int s = is_plus? (a+b) : (a*b);
            stack.push(s);
        }
    }
    if (stack.empty())
        return -1;
    else
        return stack.top();
}

int main() {

	string s = "44*4*4*4*4*1+";
	cout << solution(s) << endl;

	return 0;
}