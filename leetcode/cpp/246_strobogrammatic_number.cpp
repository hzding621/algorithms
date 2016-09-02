#include <iostream>

using namespace std;

class Solution {
public:
    bool isStrobogrammatic(string num) {
        // first check first half
        int len = num.length();
        for (int i = 0; i < len / 2; i++) {
            if (!isStrobogrammaticDigit(num[i])) return false;
        }

        // check middle if odd length
        if (len % 2 && !isStrobogrammaticCenterDigit(num[len / 2])) return false;

        // then check second half
        for (int i = len - 1; i >= (len+1)/2; i--) {
            if (!isStrobogrammaticDigit(num[i]) || getMatchingDigit(num[i]) != num[len-1-i]) return false;
        }

        return true;
    }
private:
    bool isStrobogrammaticDigit(char c) {
        return isStrobogrammaticCenterDigit(c) || c == '6' || c == '9';
    }

    bool isStrobogrammaticCenterDigit(char c) {
        return c == '0' || c == '1' || c == '8';
    }

    char getMatchingDigit(char c) {
        switch (c) {
            case '0':
                return '0';
            case '1':
                return '1';
            case '6':
                return '9';
            case '8':
                return '8';
            case '9':
                return '6';
            default:
                throw invalid_argument("Not a valid strobogrammatric digit!");
        }
    }
};

int main() {

    Solution sol;
    cout << sol.isStrobogrammatic("1691") << endl;
    cout << sol.isStrobogrammatic("16091") << endl;
    cout << sol.isStrobogrammatic("18081") << endl;
    cout << sol.isStrobogrammatic("1413081") << endl;
    cout << sol.isStrobogrammatic("1") << endl;
    cout << sol.isStrobogrammatic("6") << endl;
    cout << sol.isStrobogrammatic("0") << endl;
    cout << sol.isStrobogrammatic("69") << endl;
    cout << sol.isStrobogrammatic("1605") << endl;

    return 0;
}