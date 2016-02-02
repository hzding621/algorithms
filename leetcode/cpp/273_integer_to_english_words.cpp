#include <string>
#include <cmath>
#include <iostream>
#define B 1000000000
#define M 1000000
#define K 1000
#define H 100
using namespace std;
string numberToWordsPos(int num) {
  string s;
  if (num < 100) {
    if (num == 0) {
      return "";
    } else if (num == 1) {
      return "One";
    } else if (num == 2) {
      return "Two";
    } else if (num == 3) {
      return "Three";
    } else if (num == 4) {
      return "Four";
    } else if (num == 5) {
      return "Five";
    } else if (num == 6) {
      return "Six";
    } else if (num == 7) {
      return "Seven";
    } else if (num == 8) {
      return "Eight";
    } else if (num == 9) {
      return "Nine";
    } else if (num == 10) {
      return "Ten";
    } else if (num == 11) {
      return "Eleven";
    } else if (num == 12) {
      return "Twelve";
    } else if (num == 13) {
      return "Thirteen";
    } else if (num == 14) {
      return "Fourteen";
    } else if (num == 15) {
      return "Fifteen";
    } else if (num == 16) {
      return "Sixteen";
    } else if (num == 17) {
      return "Seventeen";
    } else if (num == 18) {
      return "Eighteen";
    } else if (num == 19) {
      return "Nineteen";
    } else {
      string k;
      if (num < 30)
        k = "Twenty";
      else if (num < 40)
        k = "Thirty";
      else if (num < 50)
        k = "Forty";
      else if (num < 60)
        k = "Fifty";
      else if (num < 70)
        k = "Sixty";
      else if (num < 80)
        k = "Seventy";
      else if (num < 90)
        k = "Eighty";
      else
        k = "Ninety";
      s += k;
      string t = numberToWordsPos(num % 10);
      if (t.length() > 0)
        s += " ";
      s += t;
    }
  }
  else {
    int unit = (num >= B) ? B : (num >= M) ? M : (num >= K) ? K : H;
    s = numberToWordsPos(num/unit);
    s += (unit == B) ? " Billion" :
         (unit == M) ? " Million" :
         (unit == K) ? " Thousand" : " Hundred";
    string t = numberToWordsPos(num % unit);
    if (t.length() > 0) s += " ";
    s += t;
  }
  return s;
}
string numberToWords(int num) {
  if (num == 0)
    return "Zero";
  else
    return numberToWordsPos(num);
}

int main() {

  cout << numberToWords(100) << endl;
  return 0;
}
