#include <iostream>
#include <string>
#include <sstream>
#include <unordered_map>
using namespace std;
bool wordPattern(string pattern, string str) {
  unordered_map<char, string> _map;
  unordered_map<string, char> _rev_map;
  istringstream iss(str);
  string tok;
  for (int i=0; i<pattern.length(); i++) {
    char c = pattern[i];
    if (!getline(iss, tok, ' '))
      return false;
    if (_map.find(c) != _map.end()) {
      if (_map[c] != tok)
        return false;
    } else {
      _map[c] = tok;
    }
    if (_rev_map.find(tok) != _rev_map.end()) {
      if (_rev_map[tok] != c)
        return false;
    } else {
      _rev_map[tok] = c;
    }
  }
  return !getline(iss, tok, ' ');
}
int main() {

  cout << boolalpha;
  cout << wordPattern("abba", "dog cat cat dog") << endl;
  cout << wordPattern("abba", "dog cat cat fish") << endl;
  cout << wordPattern("aaaa", "dog cat cat dog") << endl;
  cout << wordPattern("abba", "dog dog dog dog") << endl;

  return 0;
}
