#include <iostream>

using namespace std;

class Solution {
public:
    bool isPerfectSquare(int num) {
        return binarySearchSquare(num, 0, num);
    }

private:

    bool binarySearchSquare(int target, int left, int right) {
        if (left > right) return false;
        if (left == right) {
            long square = left;
            square *= square;
            return square == target;
        }
        long middle = left + (right - left) / 2;
        long square = middle * middle;
        if (square == target) {
            return true;
        }
        else if (square < target) {
            return binarySearchSquare(target, middle + 1, right);
        } else {
            return binarySearchSquare(target, left, middle - 1);
        }
    }
};

int main() {

    Solution solution;
    cout << boolalpha;
    for (int i = 0; i < 50; i++) {
        cout << i << " " << solution.isPerfectSquare(i) << endl;
    }

    cout << INT_MAX << " " << solution.isPerfectSquare(INT_MAX) << endl;
    cout << 808201 << " " << solution.isPerfectSquare(808201) << endl;

    return 0;
}