#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <string>
#include <iostream>
#include <stack>
#include <queue>

using namespace std;

int main() {

  int n;
  scanf("%d\n\n", &n);
  while (n-- > 0) {
    bool init = true;
    stack<char> _ops;
    stack<char> _nums;
    string s;
    while(getline(cin, s), s != "") {
      char c = s[0];
      if (c == '(') {
        _ops.push(c);
      } else if (c == ')') {
        while (_ops.top() != '(') {
          printf("%c", _ops.top());
          _ops.pop();
        }
        _ops.pop();
      } else if (c == '*' || c == '/') {
        while (!_ops.empty() && (_ops.top() == '*' || _ops.top() == '/')) {
          printf("%c", _ops.top());
          _ops.pop();
        }
        _ops.push(c);
      } else if (c == '+' || c == '-') {
        while (!_ops.empty() && _ops.top() != '(') {
          printf("%c", _ops.top());
          _ops.pop();
        }
        _ops.push(c);
      } else {
        printf("%c", c);
      }
    }
    while (!_ops.empty()) {
      printf("%c", _ops.top());
      _ops.pop();
    }
    printf("\n");
    if (n > 0)
      printf("\n");
  }

  return 0;
}
