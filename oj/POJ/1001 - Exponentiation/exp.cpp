#include <cstdlib>
#include <cstdio>
#include <string>
#include <iostream>
#include <utility>
#include <vector>
using namespace std;

pair<string,int> normalize(string s) {
  int n = s.size();
  int i = n-1;
  int e = 0;
  while (i >= 0 && s[i] != '.') {
    i--;
  }
  if (i >= 0) {
    e = -(n - i - 1);
    s.erase(s.begin() + i);
  }
  n = s.size();
  i = 0;
  while (i < n && s[i]=='0')
    i++;
  s = s.substr(i);
  n = s.size();
  i = n-1;
  while (i >= 0 && s[i]=='0') {
    i--;
    e++;
  }
  s = s.substr(0, i+1);
  if (s.empty()) return make_pair("0", 0);
  return make_pair(s, e);
}

string integerMult(const string& a, const string& b) {
  string rt(a.size()+b.size(), '0');
  for (int i = a.size() - 1; i >= 0 ; i--)
  {
    int carry = 0;
    int an = a[i] - '0';
    for (int j = b.size() - 1; j >= 0 ; j--)
    {
        int bn = b[j] - '0';
        int sum = an * bn + carry + rt[i+j+1] - '0';
        carry = sum / 10;
        rt[i+j+1] = sum % 10 + '0';
    }
    if (carry) rt[i] += carry;
  }
  int i = 0;
  while (i < rt.size() && rt[i] == '0')
    i++;
  rt = rt.substr(i);
  return rt;
}

string integerExp(const string& s, int n) {
  if (s == "0" || n == 1) return s;
  if (n == 0) return "1";

  string rt = integerExp(s, n/2);
  rt = integerMult(rt, rt);
  if (n % 2) rt = integerMult(rt, s);
  return rt;
}

string floatExp(const string& s, int n) {
  pair<string,int> p = normalize(s);
  int e = p.second * n;
  string intPart = integerExp(p.first, n);
  if (e > 0) {
    for (int i=0; i<e; i++)
      intPart.push_back('0');
  } else if (e < 0) {
    int len = intPart.length();
    if (-e < len) {
      intPart.insert(intPart.end()+e, '.');
    }
    else {
      string prefix = ".";
      for (int k=0; k<-e-len; k++) {
        prefix.push_back('0');
      }
      intPart = prefix + intPart;
    }
  }
  return intPart;
}

int main() {
  string s;
  int n;
  while (cin >> s >> n) {
    cout << floatExp(s, n) << endl;
  }
}
