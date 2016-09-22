#include <iostream>

using namespace std;

class Solution {
public:
    int integerReplacement(int n) {
        if (n == 1) return 0; // edge case
        if (n == 3) return 2; // edge case
        if (n == INT_MAX) return 32; // edge case
        if (n & 1) {
            if ((n + 1 ) % 4 ==0) {
                return integerReplacement(n + 1) + 1;
            } else {
                return integerReplacement(n - 1) + 1;
            }
        } else {
            return integerReplacement(n / 2) + 1;
        }
    }
};

int main() {

    Solution solution;
    cout << solution.integerReplacement(7) << endl;

    return 0;
}