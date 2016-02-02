#include <iostream>
#include <climits>

using namespace std;

class Solution {
public:
    int divide(int dividend, int divisor) {
        if (dividend == INT_MIN && divisor == -1)
            return INT_MAX;
        return divide_long(dividend, divisor);
    }
private:
    long divide_long(long dividend, long divisor) {
        if (divisor == 0)
            return INT_MAX;

        bool isPositive = (dividend > 0 && divisor > 0) || (dividend < 0 && divisor < 0);
        dividend = abs(dividend);
        divisor = abs(divisor);
        if (dividend < divisor)
            return 0;
        else if (divisor == 1)
            return isPositive ? dividend : -dividend;
        int n = divisor, c = 1;
        while (n+n < dividend && n+n > 0) {
            n += n;
            c += c;
        }
        int r = c + divide(dividend-n, divisor);
        return isPositive ? r : -r;
    }
};

int main() {
    Solution sol;
    cout << sol.divide(-2147483648, -1) << ": " << (-2147483648)/(-1) << endl;
    return 0;
}
