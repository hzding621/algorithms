#include <iostream>

using namespace std;

class Solution {
public:
    string toHex(int num) {
        if (num == 0) return "0";
        string s;
        char lsb = 0;
        unsigned int n = (unsigned int) num;
        while (n != 0) {
            for (int i = 0; i < 4; i++) {
                lsb |= (n & 1) << i;
                n >>= 1;
            }
            if (lsb < 10) {
                s.push_back(lsb + '0');
            } else {
                s.push_back(lsb - 10 + 'a');
            }
            lsb = 0;
        }
        reverse(s.begin(), s.end());
        return s;
    }
};

int main() {

    Solution solution;
    cout << solution.toHex(26) << endl;
}