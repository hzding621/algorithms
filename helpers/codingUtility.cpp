#ifndef __CODING_UTILITY__
#define __CODING_UTILITY__
#include <iostream>
#include <cstdio>
#include <string>
#include <sstream>
#include <cstring>
#include <vector>

using namespace std;

void print2DIntArray(vector<vector<int>>& vv) {
  for (auto& v : vv) {
    for (int i: v)
      cout << i << " ";
    cout << endl;
  }
}

vector<vector<int>> generate2DIntArray(string s) {
  istringstream iss(s);
  vector<vector<int>> vv;
  iss.ignore();
  int i;
  while (iss.peek() == '[') {
    iss.ignore();
    vector<int> v;
    while (iss.peek() != ']') {
      iss >> i;
      v.push_back(i);
      if (iss.peek() == ',')
        iss.ignore();
    }
    vv.push_back(v);
    iss.ignore();
    if (iss.peek() == ',')
      iss.ignore();
  }
  return vv;
}

#endif
