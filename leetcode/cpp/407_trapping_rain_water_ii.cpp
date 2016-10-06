#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    int trapRainWater(vector<vector<int>>& heightMap) {
        int n = (int) heightMap.size(); if (n == 0) return 0;
        int m = (int) heightMap[0].size(); if (m == 0) return 0;
        using triple = tuple<int,int,int>; // height, x, y
        priority_queue<triple, vector<triple>, greater<triple>> boundary;
        vector<vector<bool>> visited;
        for (int i = 0; i < n; i++) {
            visited.emplace_back(m);
        }
        for (int i = 0; i < n; i++) {
            boundary.emplace(heightMap[i][0], i, 0);
            boundary.emplace(heightMap[i][m-1], i, m - 1);
            visited[i][0] = visited[i][m-1] = true;
        }
        for (int j = 1; j < m - 1; j++) {
            boundary.emplace(heightMap[0][j], 0, j);
            boundary.emplace(heightMap[n-1][j], n - 1, j);
            visited[0][j] = visited[n-1][j] = true;
        }
        int total = 0;
        vector<vector<int>> dirs = {{1,0}, {-1,0}, {0, 1}, {0, -1}};
        while (boundary.size()) {
            int h, x, y;
            tie(h, x, y) = boundary.top(); boundary.pop();
            for (auto& dir: dirs) {
                int x2 = x + dir[0], y2 = y + dir[1];
                if (x2 < 0 || x2 >= n || y2 < 0 || y2 >= m || visited[x2][y2]) {
                    continue;
                }
                visited[x2][y2] = true;
                total += max(0, h - heightMap[x2][y2]);
                boundary.emplace(max(h, heightMap[x2][y2]), x2, y2);
            }
        }
        return total;
    }
};

int main() {

    vector<pair<vector<vector<int>>, int>> tests = {
            {
                    {
                            {1, 4, 3, 1, 3, 2},
                            {3, 2, 1, 3, 2, 4},
                            {2, 3, 3, 2, 3, 1}
                    }, 4
            },
            {
                    {
                            {12,13, 1,12},
                            {13, 4,13,12},
                            {13, 8,10,12},
                            {12,13,12,12},
                            {13,13,13,13}
                    }, 14
            },

    };

    Solution solution;
    for (auto& t: tests) {
        cout << "expected: " << t.second << " actual: " << solution.trapRainWater(t.first) << endl;
//        cout << solution.trapRainWater(t.first);
    }

}