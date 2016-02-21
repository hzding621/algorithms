#include <iostream>
#include <vector>
using namespace std;
class DisjointSet {
	public:
	DisjointSet(int n) : arr_(n,-1), sz_(n) {}
	int find(int elem) {
		if (arr_[elem] < 0)
			return elem;
		else
			return arr_[elem] = find(arr_[elem]);
	}
	void merge(int a, int b) {
		int a_root = find(a);
		int b_root = find(b);
		if (a_root == b_root)
			return;
		if (arr_[a_root] > arr_[b_root]) {	
			arr_[b_root] += arr_[a_root];
			arr_[a_root] = b_root;
		} else {
			arr_[a_root] += arr_[b_root];
			arr_[b_root] = a_root;
		}
		sz_--;
	}
	int size() {
		return sz_;
	}
  private:
  	vector<int> arr_;
  	int sz_;
};

int norm(int i, int j, int b, int m) {

	int k = i*m*2 + j*2 + b;
	return k;
}

int findDisjointRegion(vector<vector<char>>& region) {
	int n = region.size(); 
	if (n == 0) return 1;
	int m = region[0].size();
	if (m == 0) return 1;
	DisjointSet ds(2*n*m);
	for (int i=0; i<n; i++) {
		for (int j=0; j<m-1; j++) {
			ds.merge(norm(i, j, 1, m), norm(i, j+1, 0, m));
		}
	}
	for (int i=1; i<n; i++) {
		for (int j=0; j<m; j++) {
			char c = region[i-1][j], d = region[i][j];
			if (c == '/' && d == '/') {
				ds.merge(norm(i-1, j, 1, m), norm(i, j, 0, m));
			} else if (c == '/' && d == '\\') {
				ds.merge(norm(i-1, j, 1, m), norm(i, j, 1, m));
			} else if (c == '\\' && d == '/') {
				ds.merge(norm(i-1, j, 0, m), norm(i, j, 0, m));
			} else if (c == '\\' && d == '\\') {
				ds.merge(norm(i-1, j, 0, m), norm(i, j, 1, m));
			}
		}
	}
	return ds.size();
}

int main() {
	// vector<vector<char>> v = {
	// 	vector<char> {'/','\\','\\'},
	// 	vector<char> {'/','\\','/'},
	// 	vector<char> {'/','\\','\\'}
	// };
	vector<vector<char>> v = {
		vector<char> {'/','\\','/'},
		vector<char> {'\\','/','\\'}
	};
	cout << findDisjointRegion(v) << endl;
} 