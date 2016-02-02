#include <iostream>
#include <string>

using namespace std;

class Solution {
    public:
    
    string longestPalindrome(string s) {
            int n = s.length();
            if (n == 0)
                return "";
            int maxLen = 1;
            int start = 0;
            for (int i=0; i<n; i++) {
                        int len = 0;
                        while ( (i-len-1>=0 && i+len+1 <= n-1) && s[i-len-1]==s[i+len+1] )
                            len++;
                        if (2*len+1 > maxLen) {
                                        maxLen = 2*len+1;
                                        start = i - len;
                                    }
                    }
            for (int i=0; i<n-1; i++) {
                        int len = 0;
                        while ( (i-len>=0 && i+1+len <= n-1) && s[i-len]==s[i+1+len])
                            len++;
                        if (2*len > maxLen) {
                                        maxLen = 2*len;
                                        start = i - len + 1;
                                    }
                    }
            return s.substr(start, maxLen);
    
        }

};

int main(){
    Solution s;
    cout << s.longestPalindrome("abbbaa") << endl;

    return 0;
}
