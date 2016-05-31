#include <cstdio>
#include <iostream>
#include <vector>
#include <map>
#include <queue>
#include <climits>
#include <algorithm>

using namespace std;

int largestDistance = 0, p;

void dfs(vector<vector<pair<int,int> > >& _road, vector<bool>& _vis, int i, int dist) {
  _vis[i] = true;
  for (int j = 0; j < _road[i].size(); j++) {
    if (!_vis[_road[i][j].first]) {
      int nextDist = _road[i][j].second + dist;
      if (nextDist > largestDistance) {
        largestDistance = nextDist;
        p = _road[i][j].first;
      }
      dfs(_road, _vis, _road[i][j].first, nextDist);
    }
  }
}

int main() {

  int n, m;
  scanf("%d %d\n", &n, &m);
  vector<vector<pair<int, int> > > _road(n);
  while (m-- > 0) {
    int i,j,k;
    char c;
    scanf("%d %d %d %c", &i, &j, &k, &c);
    i--; j--;
    _road[i].push_back(make_pair(j, k));
    _road[j].push_back(make_pair(i, k));
  }
  vector<bool> _vis(n, false);
  dfs(_road, _vis, 0, 0);
  int u = p;
  fill_n(_vis.begin(), n, false);
  dfs(_road, _vis, u, 0);
  printf("%d\n", largestDistance);

  return 0;
}
