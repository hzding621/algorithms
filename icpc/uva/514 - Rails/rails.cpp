#include <iostream>
#include <sstream>
#include <stack>
#include <queue>

using namespace std;

int main() {
  while (true) {
    int x;
    cin >> x;
    if (x == 0) break;
    string s;
    getline(cin, s);
    getline(cin, s);
    while (s != "0") {
      istringstream iss(s);
      int y = x;
      queue<int> inq;
      for (int i=1; i<=x; i++)
        inq.push(i);
      stack<int> middle;
      while (y > 0) {
        y--;
        int xx;
        iss >> xx;
        if (middle.size() > 0 && middle.top() == xx) {
          middle.pop();
        } else {
          while (inq.size() != 0 && inq.front() != xx) {
            middle.push(inq.front());
            inq.pop();
          }
          if (inq.size() != 0 && inq.front() == xx) {
            inq.pop();
          } else {
            break;
          }
        }
      }
      if (y == 0)
        cout << "Yes" << endl;
      else
        cout << "No" << endl;
      getline(cin, s);
    }
    cout << endl;
  }
  return 0;
}
