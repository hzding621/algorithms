#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    bool isMatch(string s, string p) {
        int m = s.length(), n = p.length();
        bool *dp1 = new bool[2*n+2],
             *dp2 = dp1 + n + 1;
        fill_n(dp1, 2*n+2, false);
        dp1[n] = true;
        int i = n-1;
        while (i >= 0 && p[i] == '*')
            dp1[i--] = true;
        for (int i=m-1; i>=0; i--) {
            dp2[n] = false;
            for (int j=n-1; j>=0; j--) {
                char c = s[i], d = p[j];
                if (d == '*')
                    dp2[j] = dp1[j] || dp2[j+1];
                else
                    dp2[j] = dp1[j+1] && (d == '?' || c == d);
            }
            swap(dp1, dp2);
        }
        bool ret = dp1[0];
        delete[] min(dp1, dp2);
        return ret;
    }
};

int main() {

    Solution sol;
    cout << boolalpha;
    cout << sol.isMatch("aa","a") << " " << false << endl;
    cout << sol.isMatch("aa","aa") << " " << true << endl;
    cout << sol.isMatch("aaa","aa") << " " << false << endl;
    cout << sol.isMatch("aa", "*") << " " << true << endl;
    cout << sol.isMatch("aa", "a*") << " " << true << endl;
    cout << sol.isMatch("ab", "?*") << " " << true << endl;
    cout << sol.isMatch("aab", "c*a*b") << " " << false << endl;

    return 0;
}
