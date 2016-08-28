#include <iostream>
#include <vector>
#include <utility>

using namespace std;

class Solution {
public:
    vector<int> numIslands2(int m, int n, vector<pair<int, int>>& positions) {
        DisjointSet ds(m*n);
        vector<int> result;
        vector<vector<int>> directions = {{0,1}, {1,0}, {0, -1}, {-1, 0}};
        for (auto& p: positions) {
            int x, y; 
            tie(x, y) = p;
            ds.add(xyToId(x, y, n));
            for (auto& uv: directions) {
                int neighborX = x + uv[0];
                int neighborY = y + uv[1];
                if (neighborX >= 0 && neighborX < m && neighborY >= 0 && neighborY < n) {
                    ds.mergeIfExists(xyToId(x,y,n), xyToId(neighborX, neighborY, n));
                }
            }
            result.push_back(ds.count());
        }
        return result;
    }
private:
    int xyToId(int x, int y, int n) {
        return x * n + y;
    }
    class DisjointSet {
    public:
        DisjointSet(int n) : _root(n, -1), _size(n, 1), _count(0) {}

        bool exists(int id) {
            return find(id) >= 0;
        }

        void add(int id) {
            if (exists(id)) return;
            _root[id] = id;
            _count++;
        }

        int find(int id) {
            if (_root[id] < 0) return -1;
            else if (_root[id] == id) return id;
            else return _root[id] = find(_root[id]);
        }

        void mergeIfExists(int id1, int id2) {
            int root1 = find(id1);
            int root2 = find(id2);
            if (root1 == -1 || root2 == -1) return;
            if (root1 == root2) return;
            if (_size[root1] < _size[root2]) {
                // 2 has larger tree
                _size[root2] += _size[root1];
                _root[root1] = root2;
            } else {
                _size[root1] += _size[root2];
                _root[root2] = root1;
            }
            _count--;
        }

        int count() {
            return _count;
        }
    private:
        vector<int> _root;
        vector<int> _size;
        int _count;
    };
};

int main() {

    // DisjointSet set(20);
    // set.mergeIfExists(2,3);
    // set.add(2);
    // cout << set.count() << endl;
    // set.add(3);
    // cout << set.count() << endl;
    // set.mergeIfExists(2,3);
    // cout << set.count() << endl;
    // set.add(5);
    // set.add(6);
    // set.add(7);
    // set.mergeIfExists(6,5);
    // cout << set.count() << endl;

    vector<pair<int, int>> pos = {{0,0}, {0,1}, {1,2}, {2,1}};
    int m = 3, n = 3;
    Solution sol;
    auto vi = sol.numIslands2(m, n, pos);
    for (int i: vi) {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}