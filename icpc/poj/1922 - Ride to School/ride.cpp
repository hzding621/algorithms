#include <cstdlib>
#include <cstdio>
#include <algorithm>
#include <iostream>
#include <climits>
using namespace std;

int main() {
  int n;
  while (scanf("%d\n", &n),n) {
    int ans = INT_MAX;
    for (int i=0; i<n; i++) {
      int v, t;
      scanf("%d%d\n", &v, &t);
      if (t >= 0) {
        double tt = 4500.0/(v*1000/3600.0);
        if (tt > (int)tt) tt++;
        ans = min(ans, ((int)tt + t));
      }
    }
    printf("%d\n", ans);
  }
}
