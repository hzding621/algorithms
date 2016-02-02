#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <utility>
#include <algorithm>

using namespace std;

vector<vector<int>> bfs(int i, unordered_map<int,unordered_set<int>>& es,int n) {
  queue<vector<int>> q;
  vector<bool> visited(n);
  visited[i] = true;
  vector<vector<int>> longestPaths;
  vector<int> path = {i};
  q.push(path);
  longestPaths.push_back(path);
  while (q.size()) {
    auto c = q.front();
    q.pop();
    if (c.size() >= longestPaths[0].size()) {
      if (c.size() > longestPaths[0].size())
        longestPaths.clear();
      longestPaths.push_back(c);
    }
    for (int neighbor: es[c.back()]) {
      if (!visited[neighbor]) {
        visited[neighbor] = true;
        c.push_back(neighbor);
        q.push(c);
        c.pop_back();
      }
    }
  }
  return longestPaths;
}

vector<int> findMinHeightTrees(int n, vector<pair<int, int>>& edges) {

  unordered_map<int,unordered_set<int>> es;
  for (auto& p: edges) {
    es[p.first].insert(p.second);
    es[p.second].insert(p.first);
  }
  unordered_set<int> result;
  auto vs = bfs(0, es, n);
  auto vs2 = bfs(vs[0].back(), es, n);

  int dist = vs2[0].size();
  for (auto v: vs2) {
    // for (int i: v) {
    //   cout << i << " ";
    // }
    // cout << endl;
    result.insert(v[dist/2]);
    if (dist % 2 == 0)
      result.insert(v[dist/2-1]);
  }

  vector<int> r;
  for (int i: result)
    r.push_back(i);
  return r;
}

int main() {
  // 7
  // [[0,1],[1,2],[1,3],[2,4],[3,5],[4,6]]
  vector<pair<int,int>> v;
  v.push_back(make_pair(0,1));
  v.push_back(make_pair(1,2));
  v.push_back(make_pair(1,3));
  v.push_back(make_pair(2,4));
  v.push_back(make_pair(3,5));
  v.push_back(make_pair(4,6));
  auto res = findMinHeightTrees(7,v);
  for (int i: res)
    cout << i << endl;
  return 0;
}
