#include <vector>
#include <sstream>
#include <string>
#include <cctype>
#include <iostream>
using namespace std;
string replaceWord(string s, string a, string b) {
  int i=0, j=0;
  stringstream ss;
  while (i<s.length() && j < s.length()) {
    while (i<s.length() && !isalpha(s[i]))
      i++;
    if (i == s.length())
      return ss.str();
    j = i;
    while (j<s.length() && isalpha(s[j]))
      j++;
    string tok = s.substr(i, j-i+1);
    if (a == tok)
      ss << b << " ";
    else
      ss << tok << " ";
    i = j;
  }
  return ss.str();
}
int main() {
  cout << replaceWord("abc abc abb", "abc", "acc") << endl;
  return 0;
}
