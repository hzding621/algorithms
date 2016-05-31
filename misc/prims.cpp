#include <algorithm>
#include <climits>
#include <iostream>
#include <queue>
#include <utility>
#include <vector>

using namespace std;

int prims(vector<vector<pair<int,int>>>& adjacencyList) {
	int n = adjacencyList.size();
	vector<bool> discovered(n);
	priority_queue< pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>> > pq;
	discovered[0] = 1;
	int numDiscovered = 1;
	int totalWeight = 0;
	for (auto& p: adjacencyList[0])
		pq.push(make_pair(p.second, p.first));
	while (numDiscovered < n) {
		auto p = pq.top();
		pq.pop();
		int b = p.second;
		if (discovered[b])
			continue;
		for (auto& pp: adjacencyList[b])
			pq.push(make_pair(pp.second,pp.first));
		discovered[b] = 1;
		numDiscovered++;
		totalWeight += p.first;
	}
	return totalWeight;
}

int main() {

	vector<vector<pair<int,int>>> adjacencyList(4);
	adjacencyList[0].push_back(make_pair(1,2));
	adjacencyList[0].push_back(make_pair(2,1));
	adjacencyList[0].push_back(make_pair(3,3));
	adjacencyList[1].push_back(make_pair(0,2));
	adjacencyList[1].push_back(make_pair(2,4));
	adjacencyList[1].push_back(make_pair(3,2));
	adjacencyList[2].push_back(make_pair(0,1));
	adjacencyList[2].push_back(make_pair(1,4));
	adjacencyList[2].push_back(make_pair(3,2));
	adjacencyList[3].push_back(make_pair(0,3));
	adjacencyList[3].push_back(make_pair(1,2));
	adjacencyList[3].push_back(make_pair(2,2));
	cout << prims(adjacencyList) << endl;
}
