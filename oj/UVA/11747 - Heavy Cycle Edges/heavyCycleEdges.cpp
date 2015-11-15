#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <utility>
using namespace std;

class dset {
public:
dset(int n) : arr_(n, -1) {}
int find(int elem)
{
	if (arr_[elem] < 0)
		return elem;
	else
		return arr_[elem] = find(arr_[elem]);
}

void merge(int a, int b)
{
	auto a_root = find(a);
	auto b_root = find(b);

	if (a_root == b_root)
		return;

	if (arr_[a_root] > arr_[b_root])
	{
		arr_[b_root] += arr_[a_root];
		arr_[a_root] = b_root;
	}
	else
	{
		arr_[a_root] += arr_[b_root];
		arr_[b_root] = a_root;
	}
	return;
}
private:
  vector<int> arr_;
};


int main() {

  while (true) {

    int n, m;
    cin >> n >> m;

    if (n == 0 && m == 0)
      break;
    dset ds(n);
    priority_queue<pair<int, pair<int,int>>,vector<pair<int, pair<int,int>>>, greater<pair<int, pair<int,int>>> > _pq;
    int total = 0;
    for (int iii=0; iii<m; iii++ ) {
      int i, j, w;
      cin >> i >> j >> w;
      total += w;
      // cout << i << " " << j << " " << w << endl;
      _pq.push(make_pair(w, make_pair(i,j)));
    }
    // int mst = 0;
		vector<int> _heavyEdges;
    while (!_pq.empty()) {
      auto edge = _pq.top();
      _pq.pop();
      int i = edge.second.first, j = edge.second.second;
      if (ds.find(i) != ds.find(j)) {
        // mst += edge.first;
        // cout << edge.first << endl;
        ds.merge(i, j);
      } else {
				_heavyEdges.push_back(edge.first);
			}
    }
    if (_heavyEdges.size() == 0)
			printf("forest\n");
		else {
			for (int i=0; i<_heavyEdges.size(); i++) {
				if (i > 0)
					putchar(' ');
				printf("%d", _heavyEdges[i]);
			}
			printf("\n");
		}
  }
  return 0;
}
