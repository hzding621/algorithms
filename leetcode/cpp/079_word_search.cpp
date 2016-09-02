#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size();
        if (n == 0) return false;
        int m = board[0].size();
        if (m == 0) return false;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (dfs(board, word, 0, i, j)) return true;
            }
        }
        return false;
    }
private:
    bool dfs(vector<vector<char>> &board, string &word, int stringIndex, int i, int j) {
        if (i < 0 || i >= board.size() || j < 0 || j >= board[0].size()) {
            return false;
        }
        char c = board[i][j];
        if (c == ' ' || c != word[stringIndex]) {
            return false;
        }
        if (stringIndex == word.length() - 1) {
            return c == word[stringIndex];
        }
        board[i][j] = ' ';
        static vector<vector<int>> dirs = {{0,1}, {0,-1}, {1,0}, {-1,0}};
        for (auto& uv: dirs) {
            int x = i + uv[0], y = j + uv[1];
            if (dfs(board, word, stringIndex + 1, x, y)) {
                board[i][j] = c;
                return true;
            }
        }
        board[i][j] = c;
        return false;
    }
};

int main() {

    vector<vector<char>> board = {
            {'A','B','C','E'},
            {'S','F','C','S'},
            {'A','D','E','E'}
    };

    Solution sol;
    cout << sol.exist(board, "ABCCED") << endl;
    cout << sol.exist(board, "SEE") << endl;
    cout << sol.exist(board, "ABCB") << endl;

    return 0;
}