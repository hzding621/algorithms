#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    bool canWin(string s) {
        int n = s.size();
        for (int i = 0; i < n - 1; i++) {
            if (s[i] == '+' && s[i + 1] == '+') {
                s[i] = s[i + 1] = '-';
                bool result = canWin(s);
                s[i] = s[i + 1] = '+';
                if (!result) return true;
            }
        }
        return false;
    }
};

int main() {

    Solution sol;
    string s = "--";
    cout << sol.canWin(s) << endl;
    return 0;
}