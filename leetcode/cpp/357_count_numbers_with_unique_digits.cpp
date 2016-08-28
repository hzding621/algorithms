#include <iostream>
#include <cmath>

using namespace std;

class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        // the first digit have 9 choices
        if (n > 10) n = 10;
        if (n == 0) return 1;
        if (n == 1) return 10;
        int firstDigit = 9;
        for (int i = 1; i < n; i++) {
            firstDigit *= (10 - i);
        }
        return firstDigit + countNumbersWithUniqueDigits(n - 1);
    }
};

int main() {

    Solution sol;
    for (int i = 1; i <= 11; i++)
    cout << sol.countNumbersWithUniqueDigits(i) << endl;

    return 0;
}