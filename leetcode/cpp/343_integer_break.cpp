#include <iostream>

using namespace std;

class Solution {
public:
    int integerBreak(int n) {
        if (n == 2) {
            return 1;
        }
        if (n == 3) {
            return 2;
        }
        if (n == 4) {
            return 4;
        }
        int a = 2, b = 3, c = 4;
        for (int i = 5; i <= n; i++) {
            int d = a * 3;
            a = b, b = c, c = d;
        }
        return c;
    }
};

int main() {

    Solution sol;
    cout << sol.integerBreak(10) << endl;

    return 0;
}