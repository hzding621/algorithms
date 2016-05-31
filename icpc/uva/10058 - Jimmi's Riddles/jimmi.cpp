#include <iostream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;
string verb[] = { "hate", "love", "know", "like"};
string noun[] = { "tom", "jerry", "goofy", "mickey", "jimmy", "dog", "cat", "mouse"};
bool isVerb(string& s) {
  string st = s.substr(0, 4);
  bool f = false;
  for (int i=0; i<4; i++)
    if (verb[i] == st)
      f = true;
  if (!f)
    return false;
  for (int i=4; i<s.length(); i++)
    if (s[i] != 's')
      return false;
  return true;
}
bool isNoun(string& s) {
  for (int i=0; i<8; i++)
    if (s == noun[i])
      return true;
  return false;
}
bool isArticle(string& s) {
  return (s == "a" || s == "the");
}
int main() {

  string str;
  while(getline(cin, str)) {
    bool judgement = true;
    bool lastIsArticle = false;
    bool lastIsAnd = true;
    bool lastIsNoun = false;
    bool verbAppeared = false;
    istringstream iss(str);
    string s;
    while(iss >> s) {
      // cout << s << endl;
      if (judgement == false)
        continue;
      bool isN = isNoun(s), isV = isVerb(s), isA = isArticle(s);
      if (s == ",") {
        if (lastIsArticle || lastIsAnd || !verbAppeared)
          judgement = false;
        else {
          verbAppeared = false;
          lastIsAnd = true;
          lastIsNoun = false;
        }
      } else if (s != "and" && !isV && !isN && !isA) {
        judgement = false;
      } else if (lastIsAnd && !isN && !isA)  {
        judgement = false;
      } else if (lastIsArticle && !isN) {
        judgement = false;
      } else if (lastIsNoun && (isN || isA)) {
        judgement = false;
      } else if (verbAppeared && isV) {
        judgement = false;
      } else if (s == "and") {
        lastIsAnd = true;
        lastIsArticle = false;
        lastIsNoun = false;
      } else if (isA) {
        lastIsAnd = false;
        lastIsArticle = true;
        lastIsNoun = false;
      } else if (isN) {
        lastIsAnd = false;
        lastIsArticle = false;
        lastIsNoun = true;
      } else {
        // verb
        lastIsAnd = true;
        lastIsArticle = false;
        lastIsNoun = false;
        verbAppeared = true;
      }
    }
    if (lastIsArticle || lastIsAnd || !verbAppeared)
      judgement = false;
    if (judgement)
      cout << "YES I WILL" << endl;
    else
      cout << "NO I WON\'T" << endl;
  }
  return 0;
}
