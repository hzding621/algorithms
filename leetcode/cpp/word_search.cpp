#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {

        if (board.size() == 0 || board[0].size() == 0)
            return false;

        if (word.length() == 0)
            return true;

        for (int i=0; i<board.size(); i++) {
            for (int j=0; j<board[i].size(); j++) {
                if (board[i][j] != word[0])
                    continue;
                bool res = false;
                char c = board[i][j];
                board[i][j] = ' ';
                backtrack(board, i, j, word, 1, &res);
                board[i][j] = c;
                if (res)
                    return true;
            }
        }
        return false;
    }
private:
    const static char _unique_char = ' ';
    void backtrack(vector<vector<char>>& board,  int i, int j, const string& word, int index, bool* res) {
        if (index == word.length()) {
            *res = true;
            return;
        }

        char c;
        if (i > 0 &&  word[index] == board[i-1][j]) {
            c = board[i-1][j];
            board[i-1][j] = _unique_char;
            backtrack(board, i-1, j, word, index+1, res);
            board[i-1][j] = c;
            if (*res) return;
        }
        if (j > 0 &&  word[index] == board[i][j-1]) {

            c = board[i][j-1];
            board[i][j-1] = _unique_char;
            backtrack(board, i, j-1, word, index+1, res);
            board[i][j-1] = c;
            if (*res) return;
        }
        if (i < board.size()-1 && word[index] == board[i+1][j]) {
            c = board[i+1][j];
            board[i+1][j] = _unique_char;
            backtrack(board, i+1, j, word, index+1, res);
            board[i+1][j] = c;
            if (*res) return;
        }
        if (j < board[i].size()-1 && word[index] == board[i][j+1]) {
            c = board[i][j+1];
            board[i][j+1] = _unique_char;
            backtrack(board, i, j+1, word, index+1, res);
            board[i][j+1] = c;
            if (*res) return;
        }
    }

};

int main() {

    Solution sol;

    vector<vector<char>> board;
    board.push_back(vector<char>{'A','B','C','E'});
    board.push_back(vector<char>{'S','F','C','S'});
    board.push_back(vector<char>{'A','D','E','E'});

    cout << boolalpha;
    cout << sol.exist(board, "ABCCED") << endl;

    return 0;
}