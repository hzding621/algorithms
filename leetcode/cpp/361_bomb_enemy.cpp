#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maxKilledEnemies(vector<vector<char>>& grid) {
        int n = grid.size();
        if (n == 0) return 0;
        int m = grid[0].size();
        if (m == 0) return 0;
        auto rows = killInRows(grid, n, m);
        auto columns = killInColumns(grid, n, m);
        int globalMax = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                globalMax = max(globalMax, rows[i][j] + columns[j][i]);
            }
        }
        return globalMax;
    }
private:
    vector<vector<int>> killInRows(vector<vector<char>>& grid, int n, int m) {
        vector<vector<int>> count;
        for (int i = 0; i < n; i++) {
            vector<int> left(m), right(m), sum(m);
            for (int j = 1; j < m; j++) {
                if (grid[i][j] == 'W') {
                    continue;
                }
                left[j] = left[j-1] + (grid[i][j-1] == 'E');
            }

            for (int j = m-2; j >= 0; j--) {
                if (grid[i][j] == 'W') {
                    continue;
                }
                right[j] = right[j+1] + (grid[i][j+1] == 'E');
            }
            for (int j = 0; j < m; j++) {
                sum[j] = grid[i][j] == 'E' ? 0 : left[j] + right[j];
            }
            count.push_back(sum);
        }
        return count;
    }

    vector<vector<int>> killInColumns(vector<vector<char>>& grid, int n, int m) {
        vector<vector<int>> count;
        for (int j = 0; j < m; j++) {
            vector<int> up(n), down(n), sum(n);
            for (int i = 1; i < n; i++) {
                if (grid[i][j] == 'W') {
                    continue;
                }
                up[i] = up[i-1] + (grid[i-1][j] == 'E');
            }

            for (int i = n-2; i >= 0; i--) {
                if (grid[i][j] == 'W') {
                    continue;
                }
                down[i] = down[i+1] + (grid[i+1][j] == 'E');
            }
            for (int i = 0; i < n; i++) {
                sum[i] = grid[i][j] == 'E' ? 0 :up[i] + down[i];
            }
            count.push_back(sum);
        }
        return count;
    }
};

int main() {

    vector<vector<char>> grid = {
        {'0', 'E', 'W', 'E'},
        {'E', 'E', 'W', 'E'},
        {'E', 'E', 'W', 'E'},
        // {'E', '0', 'W', 'E'},
        // {'0', 'E', '0', '0'}
    };

    Solution sol;
    cout << sol.maxKilledEnemies(grid) << endl;

    return 0;
}