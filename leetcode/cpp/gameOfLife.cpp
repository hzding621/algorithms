#include <iostream>
#include <vector>
#include "codingUtility.cpp"
using namespace std;
void update(vector<vector<int>>& board, int i, int j) {
  // cout << "(" << i << "," << j << ")" << endl;
  int liveNeighbors = 0;
  if (i > 0 && board[i-1][j] & 1)
    liveNeighbors++;
  if (i < board.size()-1 && board[i+1][j] & 1)
    liveNeighbors++;
  if (j > 0 && board[i][j-1] & 1)
    liveNeighbors++;
  if (j < board[0].size() && board[i][j+1] & 1)
    liveNeighbors++;
  if (i > 0 && j > 0 && board[i-1][j-1] & 1)
    liveNeighbors++;
  if (i > 0 && j < board[0].size()-1 && board[i-1][j+1] & 1)
    liveNeighbors++;
  if (i < board.size()-1 && j > 0 && board[i+1][j-1] & 1)
    liveNeighbors++;
  if (i < board.size()-1 && j < board[0].size()-1 && board[i+1][j+1] & 1)
    liveNeighbors++;
  if ((board[i][j] && (liveNeighbors == 2 || liveNeighbors == 3))
      || (!board[i][j] && liveNeighbors == 3) )
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
      board[i][j] = board[i][j] >> 1;
    }
  }
}
int main() {
  vector<vector<int>> v = generate2DIntArray("[[0,0,0,0,0,0],[0,0,1,1,0,0],[0,1,0,0,1,0],[0,0,1,0,1,0],[0,0,0,1,0,0],[0,0,0,0,0,0]]");
  gameOfLife(v);
  print2DIntArray(v);
  cout << endl;
  std::vector<std::vector<int>> sol = generate2DIntArray(
    "[[0,0,0,0,0,0],[0,0,1,1,0,0],[0,1,0,0,1,0],[0,0,1,0,1,0],[0,0,0,1,0,0],[0,0,0,0,0,0]]"
  );
  print2DIntArray(sol);
  return 0;
}
