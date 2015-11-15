#include <iostream>
#include <cctype>
using namespace std;
bool isAlpha(char c) {
  return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');
}
int removeInitial(char inputString[], char c, int length) {
  // remove all words that start with initial c and return new length
  int i = 0, j = 0;
  int currentState = 0; // 0 for search, 1 for copying, 2 for skipping
  while (j < length) {
    if (currentState == 0) {
      if (inputString[j] == tolower(c) || inputString[j] == toupper(c)) {
        currentState = 2;
      } else if (isAlpha(inputString[j])) {
        currentState = 1;
        inputString[i++] = inputString[j];
      }
    } else if (currentState == 1) {
      if (!isAlpha(inputString[j])) {
        currentState = 0;
        inputString[i++] = ' ';
      } else {
        inputString[i++] = inputString[j];
      }
    } else {
      if (!isAlpha(inputString[j])) {
        currentState = 0;
      }
    }
    j++;
  }
  return inputString[i-1] == ' ' ? (i-1) : i;
}

int main() {
  char ca[] = "  a   big Bag Ball is   running ";
  int k = removeInitial(ca, 'b', 32);
  cout << k << endl;
  for (int i=0;i<k;i++)
    cout << ca[i];
  cout << endl;

}
