#include <iostream>
#include <vector>
using namespace std;
bool isValid(vector<vector<char>>& board, int i, int j) {
  char cc = board[i][j];
  for (int k=0; k<9; k++) {
    if (k != i && board[k][j] == cc) return false;
    if (k != j && board[i][k] == cc) return false;
  }
  int r = i/3, c = j/3;
  for (int m=r*3; m<r*3+3; m++) {
    for (int n=c*3; n<c*3+3; n++) {
      if (m == i && n == j) continue;
      if (cc == board[m][n]) return false;
    }
  }
  return true;
}
bool solveSudokuHelper(vector<vector<char>>& board, int ci, int cj) {
  if (ci == 9) return true;
  int ni = cj == 8 ? (ci + 1) : ci,
      nj = cj == 8 ? 0 : (cj + 1);
  if (board[ci][cj] != '.') {
    if (!isValid(board, ci, cj)) return false;
    return solveSudokuHelper(board, ni, nj);
  }
  for (char p='1'; p<='9'; p++) {
    board[ci][cj] = p;
    if (isValid(board, ci, cj) && solveSudokuHelper(board, ni, nj))
      return true;
  }
  board[ci][cj] = '.';
  return false;
}
void solveSudoku(vector<vector<char>>& board) {
  solveSudokuHelper(board, 0, 0);
}
int main() {
  vector<string> v = {
    "53..7....",
    "6..195...",
    ".98....6.",
    "8...6...3",
    "4..8.3..1",
    "7...2...6",
    ".6....28.",
    "...419..5",
    "....8..79"
  };
  vector<vector<char>> vv;
  for (string& s : v) {
    vv.emplace_back();
    for (char c : s) {
      vv.back().push_back(c);
    }
  }
  solveSudoku(vv);
  for (int i=0; i<vv.size(); i++) {
    for (int j=0; j<vv[0].size(); j++) {
      cout << vv[i][j];
    }
    cout << endl;
  }
  return 0;
}
