#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int numDecodings(string s) {
        return numDecodings(s, true);
    }
private:
    unordered_map<string, int> memoization;

    int numDecodings(string s, bool isStart) {
        if (isStart && s == "")
            return 0;
        if (memoization.count(s))
            return memoization[s];
        if (s.length() == 0) {
            memoization[s] = 1;
            return 1;
        }
        if (s[0] == '0')
            return 0;
        int count = numDecodings(s.substr(1), false);
        if (s.length() >= 2) {
            char c1 = s[0], c2 = s[1];
            if ((c1 == '2' && c2 <= '6') || c1 <= '1') {
                count += numDecodings(s.substr(2), false);
            }
        }
        memoization[s] = count;
        return count;
    }
};

int main() {

    Solution sol;
    // cout << sol.numDecodings("") << endl;
    cout << sol.numDecodings("01") << endl;
    // cout << sol.numDecodings("012") << endl;
    // cout << sol.numDecodings("207") << endl;

    return 0;
}
