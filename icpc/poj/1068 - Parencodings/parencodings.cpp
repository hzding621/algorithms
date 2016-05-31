#include <vector>
#include <cstdio>
#include <iostream>
using namespace std;
int main() {
  int n;
  cin >> n;
  while(n-- >0) {
    int len;
    cin >> len;
    vector<int> v;
    int last = 0;
    for (int i=0; i<len; i++) {
      int k;
      cin >> k;
      for (int j=0; j<(k-last);j++) {
        for (int m=0; m<v.size(); m++)
          v[m]++;
        v.push_back(1);
      }
      cout << v.back() << " ";
      v.pop_back();
      last = k;
    }
    cout << endl;
  }
  return 0;
}
