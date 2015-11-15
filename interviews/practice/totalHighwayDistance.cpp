#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <queue>
#include <utility>
#include <algorithm>

using namespace std;

unordered_map<int, unordered_map<int,int>> graph;
int THD = 0;

int main() {

	int n, q;
	scanf("%d %d\n", &n, &q);
	for (int ii=0;ii<n-1;ii++) {
		int i, j, w;
		scanf("%d %d %d\n", &i, &j, &w);
		i--, j--;
		graph[i][j]=w;
		graph[j][i]=w;
	}
	for (int ii=0; ii<n; ii++) {
		vector<bool> vis(n,false);
		queue<pair<int,int>> qu;
		qu.push(make_pair(ii, 0));
		vis[ii] = true;
		while (!qu.empty()) {
			auto cur = qu.front();
			qu.pop();
			int i = cur.first;
			for (auto e: graph[i]) {
				int j = e.first;
				if (!vis[j]) {
					vis[j] = true;
					// remove the back edge from tree
					if (ii == n-1)
						graph[j].erase(i);
					qu.push(make_pair(j, cur.second+graph[i][j]));
					THD += cur.second + graph[i][j];
				}
			}
		}
	}
	THD /= 2;
	for (int ii=0;ii<q;ii++) {
		char s[10];
		scanf("%s", s);
		if (!strcmp(s, "QUERY")) {
			scanf("\n");
			printf("%d\n", THD);
		} else {
			int i, j, w;
			scanf("%d %d %d\n", &i, &j, &w);
			i--, j--;
			int source, wdiff, count = 1;
			if (graph[i].count(j)) {
				source = j;
				wdiff = w - graph[i][j];
			} else {
				source = i;
				wdiff = w - graph[j][i];
			}
			queue<int> q;
			q.push(source);
			while (!q.empty()) {
				int cur = q.front();
				q.pop();
				for (auto e: graph[cur]) {
					q.push(e.first);
					count++;
				}
			}
			THD += wdiff * (count) * (n - count);
		}
	}

}