#include <iostream>
#include <vector>
#include <utility>

using namespace std;

class Solution {

	void dfs(vector<vector<int>>& adjacencyList, vector<bool>& vertexMarks, int curVertex) {
		for (int neighbor: adjacencyList[curVertex]) {
			if (vertexMarks[neighbor] == 0) {
				vertexMarks[neighbor] = 1;
				dfs(adjacencyList, vertexMarks, neighbor);
			}
		}
	}
public:
	bool validTree(int n, vector<pair<int, int>>& edges) {
		vector<vector<int>> adjacencyList(n);
		if (edges.size() != n-1) return false;
		for (auto& p: edges) {
			adjacencyList[p.first].push_back(p.second);
			adjacencyList[p.second].push_back(p.first);
		}
		vector<bool> vertexMarks(n, false);
		vertexMarks[0] = 1;
		dfs(adjacencyList, vertexMarks, 0);
		for (int i=1; i<n; i++) {
			if (vertexMarks[i] == 0)
				return false;
		}
		return true;
	}
};

int main() {
	vector<pair<int,int>> edges;
	edges.push_back(make_pair(0,1));
	edges.push_back(make_pair(1,2));
	edges.push_back(make_pair(2,3));
	edges.push_back(make_pair(1,3));
	edges.push_back(make_pair(1,4));

	Solution sol;
	cout << sol.validTree(5, edges) << endl;
}