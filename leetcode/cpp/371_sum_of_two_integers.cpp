#include <iostream>

using namespace std;

class Solution {
public:
    int getSum(int a, int b) {
        if (b == 0) return a;
        else return getSum(a ^ b, (a & b) << 1);
    }
};

int main() {

    Solution solution;
    for (int i = 1; i <= 10; i++) {
        for (int j = i; j <= 10; j++) {
            cout << "sum(" << i << "," << j << ")=" << solution.getSum(i, j) << endl;
        }
    }
}