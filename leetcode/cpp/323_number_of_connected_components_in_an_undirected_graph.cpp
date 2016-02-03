#include <iostream>
#include <vector>
#include <utility>

using namespace std;

class Solution {

void dfs(vector<vector<int>>& adjacencyList, vector<bool>& marks, int currentVertex) {
	if (marks[currentVertex] == false) {
		marks[currentVertex] = true;
		for (int neighbor: adjacencyList[currentVertex])
			dfs(adjacencyList, marks, neighbor);
	}
}

public:
	int countComponents(int n, vector<pair<int, int>>& edges) {
		vector<vector<int>> adjacencyList(n);
		for (auto& p: edges) {
			adjacencyList[p.first].push_back(p.second);
			adjacencyList[p.second].push_back(p.first);
		}
		vector<bool> marks(n, false);

		int componentsCount = 0;
		for (int i=0; i<n; i++) {
			if (marks[i] == false) {
				componentsCount++;
				dfs(adjacencyList, marks, i);
			}
		}
		return componentsCount;
	}
};

int main() {

	vector<pair<int,int>> edges;
	edges.push_back(make_pair(0,1));
	edges.push_back(make_pair(1,2));
	// edges.push_back(make_pair(2,3));
	edges.push_back(make_pair(3,4));

	Solution sol;
	cout << sol.countComponents(5, edges) << endl;
}