#include <cstdlib>
#include <cstdio>
#include <algorithm>
#include <climits>
#include <cstring>

using namespace std;
int main() {

  // dp (i, j) min sum of dist of where the last post office is at i-th village
  //                              and there are a total of j post office
  // =  min k=0~(i-1), dp(k, j-1) + ( sum s_k+1^V ) <- precomputed in gain
  //
  int pos[500];
  int dp[500][40];
  int V, P;
  memset(pos, 0, sizeof(pos));
  memset(dp, 0, sizeof(dp));
  scanf("%d %d\n", &V, &P);
  for (int i=0; i<V; ++i) {
    scanf("%d ", pos+i);
  }

  int gain[500][500];
  memset(gain, 0, sizeof(gain));
  for (int i=0; i<V; i++) {
    for (int k=0; k<i; k++) {
      int offset = 0;
      for (int s=k+1; s<V; s++)
        offset += min(abs(pos[s]-pos[i]) - abs(pos[s]-pos[k]), 0);
      gain[i][k] = offset;
    }
  }

  for (int i=0; i<V; i++) {
    int dist = 0;
    for (int s=0; s<V; s++) {
      dist += abs(pos[s] - pos[i]);
    }
    dp[i][1] = dist;
    for (int j=2; j<=P; j++) {
      int minDist = 4000000;
      for (int k=0; k<=i-1; k++) {
        minDist = min(minDist, dp[k][j-1] + gain[i][k]);
      }
      dp[i][j] = minDist;
    }
  }

  int globalMin = INT_MAX;
  for (int i=0; i<V; i++) {
    globalMin = min(globalMin, dp[i][P]);
  }
  printf("%d\n", globalMin);

  return 0;
}
