#include <iostream>
#include <string>
#include <vector>
#include <climits>
#include <unordered_map>

using namespace std;

class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> demandsForChars;
        for (char c: t) {
            demandsForChars[c]++;
        }
        int demandCounter = t.size(), head = 0, tail = 0, minWin = INT_MAX, minWinHead = 0;
        while (head < s.size()) {
            if (demandsForChars[s[head++]]-- > 0) 
                demandCounter--;
            while (demandCounter == 0) {
                if (head - tail < minWin) {
                    minWin = head - (minWinHead = tail);
                }
                if (demandsForChars[s[tail++]]++ == 0) 
                    demandCounter++;
            }
        }
        return minWin == INT_MAX ? "" : s.substr(minWinHead, minWin);
    }
};

int main() {

    Solution sol;
    cout << sol.minWindow("AXXBXXCXDXXCBA", "ABCD") << endl;
    cout << sol.minWindow("AXXXBXXCXDXCA", "ABCD") << endl;
    cout << sol.minWindow("ADOBECODEBANC", "ABC") << endl;
    cout << sol.minWindow("ABC", "ABCD") << endl;

    cout << sol.minWindow("AAA", "AA") << endl;
    cout << sol.minWindow("AXXBXXCXDXXCBA", "CC") << endl;
    cout << sol.minWindow("AXXBXXCXDXXCBA", "CCA") << endl;
    cout << sol.minWindow("", "ABC") << endl;
    cout << sol.minWindow("XXXXXXXXAXX", "A") << endl;

    return 0;
}
