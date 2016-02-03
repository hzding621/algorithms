#include <iostream>
#include <vector>
#include <utility>
#include <unordered_map>
#include <unordered_set>

using namespace std;

class Solution {
	bool postOrderDFS(int cur, vector<char>& states, unordered_map<int,unordered_set<int>>& edges, vector<int>& path) {
		if (states[cur] == 1){
			return false;
		}
		else if (states[cur] == 0) {
			states[cur] = 1;
			for (int j: edges[cur])
				if (!postOrderDFS(j, states, edges, path))
					return false;
			path.push_back(cur);
			states[cur] = 2;
		}
		return true;
	}

public:
	vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites) {
		unordered_map<int,unordered_set<int>> edges;
		for (auto& p: prerequisites)
			edges[p.first].insert(p.second);
		vector<char> states(numCourses, 0); // 0 not visited, 1 pre-visited, 2 post-visited
		vector<int> path;
		for (int i=0; i<numCourses; i++) {
			if (!postOrderDFS(i, states, edges, path))
				return {};
		}
		return path;
	}
};

void print(const vector<int>& v) {
	for (int i: v)
		cout << i << " ";
	cout << endl;
}

int main() {

	vector<pair<int,int>> prereq;
	prereq.push_back(make_pair(1,0));
	prereq.push_back(make_pair(2,0));
	prereq.push_back(make_pair(3,1));
	prereq.push_back(make_pair(3,2));
	Solution sol;
	print(sol.findOrder(4, prereq));
}
