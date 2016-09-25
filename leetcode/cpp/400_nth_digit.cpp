#include <iostream>

using namespace std;

class Solution {
public:
    int findNthDigit(int n) {
        int len = 1;
        long count = 9;
        int number = 1;
        while (n > count * len) {
            n -= count * len;
            len++;
            count *= 10;
            number *= 10;
        }
        // the number that contains nth digit has length <len>
        number += (n - 1) / len;
        string s = to_string(number);
        return s[(n-1)%len]-'0';
    }
};

int main() {
    Solution solution;
    for (int i = 1; i <= 50; i++) {
        cout << solution.findNthDigit(i) << endl;
    }
}