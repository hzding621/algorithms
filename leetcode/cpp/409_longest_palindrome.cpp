#include <iostream>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char, int> charCount;
        for (char c: s) {
            charCount[c]++;
        }
        int length = 0;
        bool hasOdd = false;
        for (const auto& kv: charCount) {
            if (kv.second % 2 == 0) {
                // appear even times
                length += kv.second;
            } else {
                // appear odd times
                length += (kv.second - 1);
                hasOdd = true;
            }
        }
        return length + hasOdd;
    }
};

int main() {

    Solution solution;
    cout << solution.longestPalindrome("aabbcc") << endl;
    cout << solution.longestPalindrome("aabbccd") << endl;
    cout << solution.longestPalindrome("abccccdd") << endl;
    cout << solution.longestPalindrome("") << endl;
    cout << solution.longestPalindrome("a") << endl;
    cout << solution.longestPalindrome("ccc") << endl;

}