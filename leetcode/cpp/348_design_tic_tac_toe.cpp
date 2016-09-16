#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <set>
#include <climits>

using namespace std;

class TicTacToe {
public:
    /** Initialize your data structure here. */
    TicTacToe(int n) {
        _n = n;
        for (int i = 0; i < n; i++) {
            _board.emplace_back(n);
        }
    }

    /** Player {player} makes a move at ({row}, {col}).
        @param row The row of the board.
        @param col The column of the board.
        @param player The player, can be either 1 or 2.
        @return The current winning condition, can be either:
                0: No one wins.
                1: Player 1 wins.
                2: Player 2 wins. */
    int move(int row, int col, int player) {
        _board[row][col] = player;
        if (checkWinning(row, col, player)) {
            return player;
        }
        return 0;
    }

private:

    vector<vector<int>> _board;
    int _n;
    vector<pair<int,int>> dirs = {
            {1, 0},
            {0, 1},
            {1, 1},
            {-1, 1}
    };

    bool checkWinning(int row, int col, int player) {

        for (auto& p: dirs) {
            int xDiff, yDiff;
            tie(xDiff, yDiff) = p;
            int sideA = count(row, col, xDiff, yDiff, player);
            int sideB = count(row, col, -xDiff, -yDiff, player);
            if (sideA + sideB + 1 >= _n) {
                return true;
            }
        }
        return false;
    }

    int count(int row, int col, int xDiff, int yDiff, int player) {
        int total = 0;
        row += xDiff, col += yDiff;
        while (row >= 0 && row < _n && col >= 0 && col < _n && _board[row][col] == player) {
            row += xDiff;
            col += yDiff;
            total++;
        }
        return total;
    }
};

int main() {

    TicTacToe ticTacToe(3);
    cout << ticTacToe.move(0, 0, 1) << endl;
    cout << ticTacToe.move(0, 2, 2) << endl;
    cout << ticTacToe.move(2, 2, 1) << endl;
    cout << ticTacToe.move(1, 1, 2) << endl;
    cout << ticTacToe.move(2, 0, 1) << endl;
    cout << ticTacToe.move(1, 0, 2) << endl;
    cout << ticTacToe.move(2, 1, 1) << endl;

    return 0;
}