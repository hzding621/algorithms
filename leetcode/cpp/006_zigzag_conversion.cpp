// https://oj.leetcode.com/problems/zigzag-conversion/

#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
	void printMap(vector<vector<char>>& map, int numRows) {
		for (int m=0; m<numRows; m++) {
			for (int n=0; n<map[m].size(); n++) {
				char c = map[m][n];
				if (c!='\0')
					cout << c;
				else
					cout << ' ';
			}
			cout << endl;
		}
	}

public:
	string convert(string s, int numRows)  {
		if (numRows == 1)
			return s;

		vector<vector<char>> map;
		for (int i=0; i<numRows; i++)
			map.emplace_back(1, '\0');

		bool goingDown = true;
		int curRow = 0, curCol = 0;
		for (int i=0; i<s.length(); i++) {
			// iterate through the characters

			map[curRow][curCol] = s[i];
			if (goingDown == true) {
				if (curRow == numRows-1) {
					for (int j=0; j<numRows; j++) {
						map[j].push_back('\0');// expand each row
					}
					goingDown = false;
					curRow--;
					curCol++;
				} else {
					curRow++;
				}
			} else {
				if (curRow == 0) {
					goingDown = true;
					curRow++;
				}
				else {
					for (int j=0; j<numRows; j++) {
						map[j].push_back('\0');// expand each row
					}
					curRow--;
					curCol++;
				}
			}
		}
		// printMap(map, numRows);
		stringstream str;
		for (int i=0; i<numRows; i++) {
			for (int j=0; j<map[i].size(); j++) {
				char c = map[i][j];
				if (c != '\0')
					str << c;
			}
		}
		return str.str();
		
	}
};

int main() {
	Solution sol;
	cout << sol.convert("PAYPALISHIRING", 3) << endl;
}