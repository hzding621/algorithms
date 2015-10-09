#include <iostream>
#include <vector>
#include "codingUtility.cpp"
using namespace std;
void update(vector<vector<int>>& board, int i, int j) {
  int m = board.size(), n = board[0].size();
  int count = 0;
  for (int ii=max(0, i-1); ii<=min(m-1, i+1); ii++) {
    for (int jj=max(0, j-1); jj<=min(n-1, j+1); jj++) {
      if (ii == i && jj == j)
        continue;
      if (board[ii][jj] & 1) count ++;
    }
  }
  if (count == 3 || count - board[i][j] == 2)
    board[i][j] |= 2;
}
void gameOfLife(vector<vector<int>>& board) {
  for (int i=0; i<board.size(); i++) {
    for (int j=0; j<board[0].size(); j++) {
      update(board, i, j);
    }
  }
  for (int i=0; i<board.size(); i++) {
    for (int j=0; j<board[0].size(); j++) {
      board[i][j] >>= 1;
    }
  }
}
int main() {
  
  return 0;
}
