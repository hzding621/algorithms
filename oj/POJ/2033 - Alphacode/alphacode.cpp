#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;
int main() {
  char s[5000];
  while (scanf("%s\n", s)) {
    if (!strcmp(s, "0"))
      break;
    int n = strlen(s);
    int dp[n+1];
    dp[0] = 1;
    // dp(k) = (0 or 1 if 1<=s[k-1]s[k] <=26
    //         + 1 if 1 <= s[k] <= 9)
    //        * dp(k-1)
    for (int i = 1; i <= n; i++) {
      char c = s[i-1];
      dp[i] = 0;
      if (c >= '1' && c <= '9')
        dp[i] += dp[i-1];
      if (i > 1) {
        char a = s[i-1], b = s[i-2];
        if (b > '0' && (10 * (b-'0') + a - '0') <= 26)
          dp[i] += dp[i-2];
      }
    }
    printf("%d\n", dp[n]);
  }

  return 0;
}
