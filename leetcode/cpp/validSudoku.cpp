#include <iostream>
#include <vector>
#include <cstdlib>
#include <cstring>
#include <utility>
using namespace std;
bool isValidSudoku(vector<vector<char>>& board) {
  // horizontal
  bool digits[9];
  for (int i=0; i<9; i++) {
    memset(digits, 0, 9);
    for (int j=0; j<9; j++) {
      char k = board[i][j];
      if (k == '.')
        continue;
      k -= '1';
      if (digits[k])
        return false;
      digits[k] = 1;
    }
  }
  // vertical
  for (int i=0; i<9; i++) {
    memset(digits, 0, 9);
    for (int j=0; j<9; j++) {
      char k = board[j][i];
      if (k == '.')
        continue;
      k -= '1';
      if (digits[k])
        return false;
      digits[k] = 1;
    }
  }
  // each block
  for (int i=0; i<3; i++) {
    for (int j=0; j<3; j++) {
      memset(digits, 0, 9);
      for (int ii=3*i; ii<(3*i+3); ii++) {
        for (int jj=3*j; jj<(3*j+3); jj++) {
          char k = board[ii][jj];
          if (k == '.')
            continue;
          k -= '1';
          if (digits[k])
            return false;
          digits[k] = 1;
        }
      }
    }
  }
  return true;
}
int main() {

  vector<string> v = {
  ".87654321",
  "2........",
  "3........",
  "4........",
  "5........",
  "6........",
  "7........",
  "8........",
  "9........"};
  vector<vector<char>> vv;
  for (string& s : v) {
    vv.emplace_back();
    for (char c : s) {
      vv.back().push_back(c);
    }
  }
  cout << boolalpha << isValidSudoku(vv) << endl;
  return 0;
}
