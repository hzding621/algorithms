#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    int shortestDistance(vector<vector<int>>& grid) {
        int n = grid.size();
        if (n == 0) return -1;
        int m = grid[0].size();
        if (m == 0) return -1;
        vector<vector<int>> totalDist;
        vector<vector<int>> reachableCount;
        for (int i = 0; i < n; i++) {
            totalDist.emplace_back(m);
            reachableCount.emplace_back(m);
        }
        int houseNo = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1) {
                    bfs(grid, totalDist, reachableCount, i, j, houseNo++);
                }
            }
        }

        int minDist = INT_MAX;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (reachableCount[i][j] == houseNo) {
                    minDist = min(minDist, totalDist[i][j]);
                }
            }
        }
        return minDist == INT_MAX ? -1 : minDist;
    }
private:
    void bfs(vector<vector<int>>& grid, vector<vector<int>>& totalDist, vector<vector<int>>& reachableCount,
             int i, int j, int houseNo) {
        queue<tuple<int,int,int>> q;
        q.push(make_tuple(i, j, 0));
        vector<vector<int>> dirs = {{0,1},{1,0},{0,-1},{-1,0}};
        while (q.size()) {
            int curI, curJ, dist;
            tie(curI, curJ, dist) = q.front(); q.pop();
            for (auto& vi: dirs) {
                int newI = curI + vi[0], newJ = curJ + vi[1];
                if (newI >= 0 && newI < grid.size() && newJ >= 0 && newJ < grid[0].size()
                    && reachableCount[newI][newJ] == houseNo && grid[newI][newJ] == 0) {
                    q.push(make_tuple(newI, newJ, dist+1));
                    reachableCount[newI][newJ]++;
                    totalDist[newI][newJ] += (dist + 1);
                }
            }
        }
    }
};
int main() {

    vector<vector<int>> grid = {
            {1, 0, 2, 0, 1},
            {0, 0, 0, 0, 0},
            {0, 0, 1, 0, 0}
    };
    Solution sol;
    cout << sol.shortestDistance(grid) << endl;
    return 0;
}