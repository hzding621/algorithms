#include <iostream>
#include <vector>
#include <utility>
#include <unordered_map>
#include <unordered_set>

using namespace std;

class Solution {
	bool dfs(vector<int>& mark, unordered_map<int,unordered_set<int>>& graph, int i) {
		if (mark[i] == 1) {
			return false; // cycle
		}
		else if (mark[i] == 0) {
			mark[i] = 1;
			for (int j: graph[i]) {
					if (!dfs(mark, graph, j)) 
						return false;
			}
			mark[i] = 2;
		}
		return true;
	}

public:
  bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
     	unordered_map<int,unordered_set<int>> g;
      for (auto p: prerequisites)
      	g[p.first].insert(p.second);
      vector<int> m(numCourses, 0); // 0, 1, 2
      for (int i=0; i<numCourses; i++) {
      	if (!dfs(m, g, i)) return false;
      }
      return true;
  }
};

int main() {
	Solution sol;
	vector<pair<int,int>> prerequisites = {make_pair(0,1),make_pair(1,0)};
	cout << sol.canFinish(2, prerequisites) << endl;
}