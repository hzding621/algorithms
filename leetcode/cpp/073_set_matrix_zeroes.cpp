/*

given a matrix of 0s and 1s, modify it so that every row/column that contained a 0 in it is all 0s.
e.g.

1110
0111
1111
1111

becomes

0000
0000
0110
0110

*/
#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        if (matrix.size() == 0 || matrix[0].size() == 0) {
            return;
        }

        bool firstColumn = false;
        for (int i = 0; i < matrix.size(); i++) {
            if (matrix[i][0] == 0) firstColumn = true;
        }
        bool firstRow = false;
        for (int i = 0; i < matrix[0].size(); i++) {
            if (matrix[0][i] == 0) firstRow  = true;
        }

        for (int i = 1; i < matrix.size(); i++) {
            for (int j = 1; j < matrix[0].size(); j++) {
                if (matrix[i][j] == 0) {
                    matrix[i][0] = matrix[0][j] = 0;
                }
            }
        }

        for (int i = 1; i < matrix.size(); i++) {
            if (matrix[i][0] == 0 ) {
                for (int j = 0; j < matrix[i].size(); j++) {
                    matrix[i][j] = 0;
                }
            }
        }

        for (int j = 1; j < matrix[0].size(); j++) {
            if (matrix[0][j] == 0 ) {
                for (int i = 0; i < matrix.size(); i++) {
                    matrix[i][j] = 0;
                }
            }
        }

        if (firstColumn) {
            for (int i = 0; i < matrix.size(); i++) {
                matrix[i][0] = 0;
            }
        }
        if (firstRow) {
            for (int j = 0; j < matrix[0].size(); j++) {
                matrix[0][j] = 0;
            }
        }
    }
};

int main() {

    vector<vector<int>> m = {
            {1, 0},
    };

    Solution sol;

    sol.setZeroes(m);

    for (auto& vi: m) {
        for (int i: vi) {
            cout << i << " ";
        }
        cout << endl;
    }

    return 0;
}
