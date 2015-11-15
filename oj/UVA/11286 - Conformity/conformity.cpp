#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <map>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

map<string, int> _map;

int main() {

  int n;
  char s[50];
  while (scanf("%d\n", &n), n) {
    _map.clear();
    while(n > 0) {
      n--;
      int v[5];
      for (int i=0; i<5; i++) {
        scanf("%d", v+i);
      }
      sort(v, v+5);
      sprintf(s, "%d%d%d%d%d", v[0], v[1], v[2], v[3], v[4]);
      _map[s]++;
      scanf("\n");
    }
    int m = 0, cnt = 0;
    for (auto it = _map.begin(); it != _map.end(); it++) {
      if (it->second > m) {
        m = it->second; cnt = 0;
      }
      if (it->second == m)
        cnt += m;
    }
    printf("%d\n", cnt);
  }
}
