#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (matrix.size() == 0 || matrix[0].size() == 0)
            return false;
        int x = 0, y = matrix[0].size()-1;
        while (x < matrix.size() && y >= 0) {
            if (matrix[x][y] == target)
                return true;
            else if (matrix[x][y] > target)
                y--;
            else
                x++;
        }
        return false;
    }
};

int main() {
    vector<int> v1 = {1, 4, 7, 11, 15};
    vector<int> v2 = {2, 5, 8, 12, 19};
    vector<int> v3 = {3, 6, 9, 16, 22};
    vector<int> v4 = {10, 13, 14, 17, 24};
    vector<int> v5 = {18, 21, 23, 26, 30};
    vector<vector<int>> matrix;
    matrix.push_back(v1);
    matrix.push_back(v2);
    matrix.push_back(v3);
    matrix.push_back(v4);
    matrix.push_back(v5);

    Solution sol;
    cout << boolalpha;
    cout << sol.searchMatrix(matrix, 5) << endl;
    cout << sol.searchMatrix(matrix, 20) << endl;

    return 0;
}
