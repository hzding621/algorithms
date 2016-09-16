#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    int minArea(vector<vector<char>>& image, int x, int y) {

        int leftBound = findInColumn(image, true, y);
        int rightBound = findInColumn(image, false, y);
        int upperBound = findInRow(image, true, x);
        int bottomBound = findInRow(image, false, x);
        return (rightBound - leftBound + 1) * (bottomBound - upperBound + 1);
    }

private:

    int findInColumn(vector<vector<char>>& image, bool isLeft, int y) {
        int left = isLeft ? 0 : y, right = isLeft ? y : ((int)image[0].size() - 1);
        while (left + 1 < right) {
            int middle = (left + right) / 2;
            if (anyBlackInColumn(image, middle)) {
                isLeft ? right = middle : left = middle;
            } else {
                isLeft ? left = middle + 1 : right = middle - 1;
            }
        }
        if (left == right) {
            return left;
        } else {
            if (isLeft) {
                return anyBlackInColumn(image, left) ? left : right;
            } else {
                return anyBlackInColumn(image, right) ? right : left;
            }
        }
    }

    int findInRow(vector<vector<char>>& image, bool isUp, int x) {
        int up = isUp ? 0 : x, bottom = isUp ? x : ((int)image.size() - 1);
        while (up + 1 < bottom) {
            int middle = (up + bottom) / 2;
            if (anyBlackInRow(image, middle)) {
                isUp ? bottom = middle : up = middle;
            } else {
                isUp ? up = middle + 1 : bottom = middle - 1;
            }
        }

        if (up == bottom) {
            return up;
        } else {
            if (isUp) {
                return anyBlackInRow(image, up) ? up : bottom;
            } else {
                return anyBlackInRow(image, bottom) ? bottom : up;
            }
        }
    }

    bool anyBlackInRow(vector<vector<char>>& image, int row) {
        for (int j = 0; j < image[row].size(); j++) {
            if (image[row][j] == '1') return true;
        }
        return false;
    }

    bool anyBlackInColumn(vector<vector<char>>& image, int column) {
        for (int i = 0; i < image.size(); i++) {
            if (image[i][column] == '1') return true;
        }
        return false;
    }
};

int main() {


    Solution sol;

    vector<vector<char>> board = {
            {'0', '0', '0', '0'},
            {'0', '0', '0', '0'},
            {'0', '1', '0', '0'}
    };

    cout << sol.minArea(board, 2, 1) << endl;

    return 0;
}