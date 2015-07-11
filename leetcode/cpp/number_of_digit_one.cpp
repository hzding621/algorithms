#include <iostream>
#include <cmath>

using namespace std;

class Solution {
public:
    int countDigitOne(int n) {
        if (n < 1)
            return 0;
        if (n < 10)
            return 1;
        int digits = log10(n);
        int buff[digits];
        buff[0] = 1;
        int m = pow(10, digits);
        int x = n / m, y = n % m;
        for (int i=1; i<digits; i++)
            buff[i] = 10 * buff[i-1] + (int)(pow(10, i));
        return (x == 1 ? (y + 1) : m)  + x * buff[digits-1] + countDigitOne(y);
    }
};

int main() {

    Solution sol;
    for (int i=0; i<10000; i++)
        cout << i << ": " << sol.countDigitOne(i) << endl;
    return 0;
}
