#include <iostream>
#include <string>
#include <utility>
#include <algorithm>

using namespace std;

class Solution {
public:
    bool isMatch(string s, string p) {
        int m = s.length(),
            n = p.length();

        bool* dp1 = new bool[2*n+2];
        bool* dp2 = dp1 + n+1;
        fill_n(dp1, 2*n+2, false);

        dp1[n] = true;
        int k = n-2;
        while (k >= 0 && p[k+1] == '*') {
            dp1[k] = true;
            k-=2;
        }
        for (int i=m-1; i>=0; i--) {
            for (int j=n-1; j>=0; j--) {
                bool equal = p[j] == '.' || p[j] == s[i];
                if (j < n-1 && p[j+1] == '*')
                    dp2[j] = dp2[j+2] || equal && dp1[j];
                else
                    dp2[j] = equal && dp1[j+1];
            }
            dp1[n] = false;
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
    cout << sol.isMatch("aa","a") << endl;
    cout << sol.isMatch("aa","aa") << endl;
    cout << sol.isMatch("aaa","aa") << endl;
    cout << sol.isMatch("aa", "a*") << endl;
    cout << sol.isMatch("aa", ".*") << endl;
    cout << sol.isMatch("ab", ".*") << endl;
    cout << sol.isMatch("aab", "c*a*b") << endl;
}