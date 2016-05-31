#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <sstream>
#include <vector>
using namespace std;

int main() {

  char s[100], s2[100];
  scanf("White: %s\n", s);
  scanf("Black: %s\n", s2);
  char board[8][8];
  memset(board, 0, 8*8);
  const char *c = strtok(s, ",");
  int x, y, t = 'P';
  if (c[0] <= 'Z') {
    t = c[0];
    c++;
  }
  y = c[0] - 'a';
  x = 7 - (c[1] - '1');
  // printf("%c, %d, %d\n", t, x, y);
  board[x][y] = t;

  for (int i=1; i<16; i++) {
    c = strtok(NULL, ",");
    if (c == NULL) break;
    int x, y, t = 'P';
    if (c[0] <= 'Z') {
      t = c[0];
      c++;
    }
    y = c[0] - 'a';
    x = 7 -( c[1] - '1');
    board[x][y] = t;
    // printf("%c, %d, %d\n", t, x, y);
  }

  c = strtok(s2, ",");
  t = 'p';
  if (c[0] <= 'Z') {
    t = c[0];
    c++;
  }
  y = c[0] - 'a';
  x = 7 -( c[1] - '1');
  board[x][y] = t - 'A' + 'a';

  for (int i=1; i<16; i++) {
    c = strtok(NULL, ",");
    if (c == NULL) break;
    int x, y, t = 'p';
    if (c[0] <= 'Z') {
      t = c[0] - 'A' + 'a';
      c++;
    }
    y = c[0] - 'a';
    x = 7 - (c[1] - '1');
    board[x][y] = t;
  }
  for (int i=0; i<8; i++) {
    printf("+---+---+---+---+---+---+---+---+\n");
    for (int j=0; j<8; j++) {
      printf("|");
      char cc = (i + j) % 2 == 0 ? '.' : ':';
      if (board[i][j])
        printf("%c%c%c", cc, board[i][j], cc);
      else
        printf("%c%c%c", cc, cc, cc);
    }
    printf("|\n");
  }
  printf("+---+---+---+---+---+---+---+---+\n");

  return 0;
}
