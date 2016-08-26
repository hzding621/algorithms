#include <iostream>
#include <vector>

using namespace std;

// Based on solution from
// https://discuss.leetcode.com/topic/30343/java-2d-binary-indexed-tree-solution-clean-and-short-17ms

class NumMatrix {
public:
    NumMatrix(vector<vector<int>> &matrix) {
        if (matrix.size() == 0 || matrix[0].size() == 0) {
            return;
        }
        _m = matrix.size();
        _n = matrix[0].size();
        for (int i = 0; i <= _m; i++) {
            _tree.emplace_back(_n + 1);
        }
        for (int i = 0; i < _m; i++) {
            _matrix.emplace_back(_n);
        }
        for (int i = 0; i < _m; i++) {
            for (int j = 0; j < _n; j++) {
                update(i, j, matrix[i][j]);
            }
        }
    }

    void update(int row, int col, int val) {
        if (_m == 0 || _n == 0) {
            return;
        }
        int diff = val - _matrix[row][col];
        for (int i = row + 1; i <= _m; i += (i & -i)) {
            for (int j = col + 1; j <= _n; j += (j & -j)) {
                _tree[i][j] += diff;
            }
        }
        _matrix[row][col] = val;
    }

    int sumRegion(int row1, int col1, int row2, int col2) const {
        if (_m == 0 || _n == 0) {
            return 0;
        }
        return sum(row2, col2) - sum(row2, col1-1) - sum(row1-1, col2) + sum(row1-1, col1-1);
    }
private:
    // 2d binary index tree
    vector<vector<int>> _tree;
    vector<vector<int>> _matrix;
    int _m = 0, _n = 0;

    int sum(int row, int col) const {
        int value = 0;
        for (int i = row + 1; i > 0; i -= (i & -i)) {
            for (int j = col + 1; j > 0; j -= (j & -j)) {
                value += _tree[i][j];
            }
        }
        return value;
    }        
};

int main() {

    vector<vector<int>> matrix = {
        {1}
    };
    NumMatrix numMatrix(matrix);
    cout << numMatrix.sumRegion(0,0,0,0) << endl;
    numMatrix.update(0,0,-1);
    cout << numMatrix.sumRegion(0,0,0,0) << endl;


    return 0;
}