#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        if (grid.size() == 0 || grid[0].size() == 0)
            return 0;
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<bool>> visited;
        for (int i=0; i<m; i++)
            visited.emplace_back(n, false);
        int count = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == '1' && !visited[i][j]){
                    visited[i][j] = true;
                    queue<int> is, js;
                    is.push(i);
                    js.push(j);
                    while (!is.empty()) {
                        int x = is.front();
                        int y = js.front();
                        is.pop();
                        js.pop();
                         if (x+1 < m && (!visited[x+1][y] && grid[x+1][y] == '1')) {
                            is.push(x+1);
                            js.push(y);
                            visited[x+1][y] = true;
                        }
                        if (x-1 >=0 && (!visited[x-1][y] && grid[x-1][y] == '1')) {
                            is.push(x-1);
                            js.push(y);
                            visited[x-1][y] = true;
                        }
                        if (y+1 < n && (!visited[x][y+1] && grid[x][y+1] == '1')) {
                            is.push(x);
                            js.push(y+1);
                            visited[x][y+1] = true;
                        }
                        if (y-1 >=0 && (!visited[x][y-1] && grid[x][y-1] == '1')) {
                            is.push(x);
                            js.push(y-1);
                            visited[x][y-1] = true;
                        }

                    }
                    count++;
                }
            }
        }
        return count;

    }
};

int main() {

	Solution s;

	vector<vector<char>> v;
	v.push_back(vector<char>{'1','0','0'});
	v.push_back(vector<char>{'1','1','0'});
	v.push_back(vector<char>{'0','0','1'});

	cout << s.numIslands(v) << endl;

	return 0;
}