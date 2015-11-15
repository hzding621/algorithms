#include <cstdlib>
#include <cstdio>
#include <climits>
#include <algorithm>
#define ll long long
using namespace std;

ll gcd(ll a, ll b) {
  if (b == 0)
    return a;
  return gcd(b, a % b);
}

ll lcm(ll a, ll b) {
  return a / gcd(a, b) * b;
}

ll coins[60];

int main() {
  int n, t;
  while (scanf("%d %d\n", &n, &t), n != 0 && t != 0) {
    for (int i=0; i<n; i++) {
      scanf("%lld\n", coins+i);
    }
    for (int i=0; i<t; i++) {
      ll ti;
      scanf("%lld\n", &ti);
      ll min = INT_MAX;
      ll max = 0;
      for (int a = 0; a < n; a++) {
        for (int b = a + 1; b < n; b++) {
          for (int c = b + 1; c < n; c++) {
            for (int d = c + 1; d < n; d++) {
              ll k = lcm(lcm(coins[a], coins[b]), lcm(coins[c], coins[d]));
              if (ti % k == 0) {
                max = std::max(max, ti);
                min = std::min(min, ti);
              } else {
                max = std::max(max, ti / k * k);
                min = std::min(min, ti / k * k + k);
              }
            }
          }
        }
      }
      printf("%lld %lld\n", max, min);
    }

  }


  return 0;
}
