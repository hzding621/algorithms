#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

class NumMatrix {
public:
    NumMatrix(vector<vector<int>> &matrix) {
    	for (int i = 0; i < matrix.size(); i++) {
    		_sumUpperLeftOf.push_back(vector<int>{});
    		int thisRow = 0;
    		for (int j = 0; j < matrix[0].size(); j++) {
    			int upperRow = (i == 0 ? 0 : _sumUpperLeftOf[i-1][j]);
    			thisRow += matrix[i][j];
    			_sumUpperLeftOf[i].push_back(upperRow + thisRow);
    		}
    	}
    }

    int sumRegion(int A, int B, int C, int D) {
        int CD = _sumUpperLeftOf[C][D];
        int AB = (A > 0 && B > 0) ? _sumUpperLeftOf[A-1][B-1] : 0;
        int CB = (B > 0) ? _sumUpperLeftOf[C][B-1] : 0;
        int AD = (A > 0) ? _sumUpperLeftOf[A-1][D] : 0;
        return CD - CB - AD + AB; 
    }
private:
	vector<vector<int>> _sumUpperLeftOf;
};


int main() {
	vector<vector<int>> matrix = {
	  vector<int>{3, 0, 1, 4, 2},
	  vector<int>{5, 6, 3, 2, 1},
	  vector<int>{1, 2, 0, 1, 5},
	  vector<int>{4, 1, 0, 1, 7},
	  vector<int>{1, 0, 3, 0, 5}
	};
	NumMatrix numMatrix(matrix);
	cout << numMatrix.sumRegion(2, 1, 4, 3) << endl;
	return 0;
}