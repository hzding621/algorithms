#include <iostream>

using namespace std;

class Solution {
public:
    bool canMeasureWater(int x, int y, int z) {
        if (z == 0) return true;
        if (x + y < z) return false;
        return z % gcd(x, y) == 0;
    }

private:
    int gcd(int x, int y) {
        if (y == 0) return x;
        return gcd(y, x % y);
    }
};

int main() {

    Solution sol;

    cout << sol.canMeasureWater(3, 5, 4) << endl;
    cout << sol.canMeasureWater(2, 6, 5) << endl;

    return 0;
}