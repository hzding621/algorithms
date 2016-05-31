#include <iostream>
#include <sstream>
#include <stack>
#include <queue>
#include <algorithm>

using namespace std;

int main() {

  string s;
  while (getline(cin, s)) {
    istringstream iss(s);
    vector<int> v;
    int x;
    while (iss >> x)
      v.push_back(x);
    for (int i=0; i<v.size(); i++) {
      cout << v[i];
      if (i < v.size()-1)
        cout << " ";
    }
    cout << endl;
    int len = v.size();
    for (int i=len; i>=1; i--) {
      int pos = max_element(v.begin(), v.begin()+i) - v.begin();
      if (pos == i-1)
        continue;
      else {
        if (pos != 0) {
          cout << len - pos << " ";
          reverse(v.begin(), v.begin()+pos+1);
        }
        cout << len - i + 1 << " ";
        reverse(v.begin(), v.begin()+i);
      }
    }
    cout << "0" << endl;
  }
  return 0;
}
