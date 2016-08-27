#include <iostream>
#include <vector>
#include <queue>
#include <utility>

using namespace std;

using triple = tuple<int,int,int>;
const int INF = 2147483647;

class Solution {
public:
    void wallsAndGates(vector<vector<int>>& rooms) {
        int n = rooms.size();
        if (n == 0) {
            return;
        }
        int m = rooms[0].size();
        if (m == 0) {
            return;
        }

        queue<triple> q;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (rooms[i][j] == 0) {
                    q.push(make_tuple(0, i, j));
                }
            }
        }
        while (!q.empty()) {
            int v, i, j;
            tie(v, i, j) = q.front();
            q.pop();
            if (i > 0 && rooms[i-1][j] == INF) {
                rooms[i-1][j] = v + 1;
                q.push(make_tuple(v + 1, i - 1, j));
            }
            if (j > 0 && rooms[i][j-1] == INF) {
                rooms[i][j-1] = v + 1;
                q.push(make_tuple(v + 1, i, j - 1));
            }
            if (i < n - 1 && rooms[i+1][j] == INF) {
                rooms[i+1][j] = v + 1;
                q.push(make_tuple(v + 1, i + 1, j));
            }
            if (j < m - 1 && rooms[i][j+1] == INF) {
                rooms[i][j+1] = v + 1;
                q.push(make_tuple(v + 1, i, j + 1));
            }
        }
    }
};

int main() {

    vector<vector<int>> grid = {
        {INF, -1, 0, INF},
        {INF, INF, INF, -1},
        {INF, -1, INF, -1},
        {0, -1, INF, INF}
    };
    Solution sol;
    sol.wallsAndGates(grid);

    for (auto& vi: grid) {
        for (int i: vi) {
            cout << i << " ";
        }
        cout << endl;
    }

    return 0;
}