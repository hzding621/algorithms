#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {

public:
    void solve(vector<vector<char>>& board) {
        int m = board.size();
        if (m == 0) return;
        int n = board[0].size();
        if (n == 0) return;
        for (int j=0; j<n; j++) {
            fill(board, 0, j);
            fill(board, m-1, j);
        }
        for (int i=1; i<m-1; i++) {
            fill(board, i, 0);
            fill(board, i, n-1);
        }
        redraw(board);
    }
private:

    void fill(vector<vector<char>>& board, int x, int y) {
        if (board[x][y] != 'O')
            return;
        int m = board.size(), n = board[0].size();
        queue<int> xs, ys;
        xs.push(x);
        ys.push(y);
        while (!xs.empty()) {
            int x = xs.front();
            int y = ys.front();
            xs.pop();
            ys.pop();
            if (x >= 0 && y >= 0 && x < m && y < n && board[x][y] == 'O') {
                board[x][y] = 'Y';
                xs.push(x-1);
                ys.push(y);
                xs.push(x);
                ys.push(y-1);
                xs.push(x+1);
                ys.push(y);
                xs.push(x);
                ys.push(y+1);
            }
        }
    }

    void redraw(vector<vector<char>>& board) {
        for (int i=0; i<board.size(); i++) {
            for (int j=0; j<board[0].size(); j++) {
                if (board[i][j] == 'Y')
                    board[i][j] = 'O';
                else
                    board[i][j] = 'X';
            }
        }
    }
};

void print(vector<vector<char>>& vv) {
    for (auto& v: vv) {
        for (char c: v) {
            cout << c << " ";
        }
        cout << endl;
    }
}

int main() {

    vector<vector<char>> board;
    vector<char> v1 = {'X', 'X', 'X', 'X'};
    vector<char> v2 = {'X', 'O', 'O', 'X'};
    vector<char> v3 = {'X', 'X', 'O', 'X'};
    vector<char> v4 = {'X', 'O', 'X', 'X'};
    board.push_back(v1);
    board.push_back(v2);
    board.push_back(v3);
    board.push_back(v4);

    Solution sol;
    sol.solve(board);

    print(board);


    return 0;
}
