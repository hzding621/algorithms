#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
	int maximalSquare(vector<vector<char>>& matrix) {
		int height = matrix.size();
		if (height == 0)
			return 0;
		int width = matrix[0].size();
		vector<vector<int>> left, up, size;
		for (int i=0; i<height; i++) {
			left.emplace_back(width);
			up.emplace_back(width);
			size.emplace_back(width);
		}
		for (int i=0; i<height; i++) {
			left[i][0] = matrix[i][0] == '1';
			size[i][0] = matrix[i][0] == '1';
		}

		for (int i=0; i<width; i++) {
			up[0][i] = matrix[0][i] == '1';
			size[0][i] = matrix[0][i] == '1';
		}

		for (int i=1; i<height; i++) {
			for (int j=1; j<width; j++) {
				if (matrix[i][j] == '1')
					left[i][j] = left[i][j-1] + 1;
				if (matrix[i][j] == '1')
					up[i][j] = up[i-1][j] + 1;
			}
		}

		for (int i=1; i<height; i++) {
			for (int j=1; j<width; j++) {
				size[i][j] = min(min(left[i][j], up[i][j]), size[i-1][j-1]+1);
			}
		}	

		int ans = 0;
		for (int i=0; i<height; i++) {
			for (int j=0; j<width; j++) {
				ans = max(ans, size[i][j]);
			}
		}

		return ans * ans;

	}
};

vector<char> tovector(string s) {
	vector<char> v;
	for (int i=0; i<s.length(); i++)
		v.push_back(s[i]);
	return v;
}

int main() {

	Solution s;

	vector<string> v = {"0000110010","0111001011","1101101000","0100110011","0111010111","0010000101","1101110111","1100101110","0001000110","0010111101","0100110000","0101001011","1110111100","0110110010","0010100000","1111010100","1011010011","1110100111","1001100100"};

	vector<vector<char>> map;
	for (string s: v)
		map.push_back(tovector(s));

	cout << s.maximalSquare(map) << endl;

	return 0;
}