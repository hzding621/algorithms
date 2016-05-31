#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <utility>
#define MAX_N 4000
using namespace std;
int dp[15000];
int dp2[15000];
int main() {
  // use up to i things and weight at most w
  // dp (i, w) = score[i] + dp (i-1, w-w[i])
  //            | dp (i-1, w)
  memset(dp, 0, sizeof(dp));
  memset(dp, 0, sizeof(dp2));
  int n, m;
  int *c = dp, *c2 = dp2;
  scanf("%d %d\n", &n, &m);
  for (int i=0; i<n; i++) {
    int w, d;
    scanf("%d %d\n", &w, &d);
    // printf("%d %d\n", w, d);
    for (int j=0; j<=m; j++) {
      if (j - w >= 0)
        c[j] = max(c2[j], d + c2[j-w]);
      else
        c[j] = c2[j];
    }
    swap(c, c2);
  }
  printf("%d\n", c2[m]);
  return 0;
}
