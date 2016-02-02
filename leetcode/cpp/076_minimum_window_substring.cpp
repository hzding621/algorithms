#include <iostream>
#include <string>
#include <vector>
#include <deque>
#include <unordered_map>

using namespace std;

class Solution {
public:
    string minWindow(string s, string t) {

        unordered_map<char, int> charCount;
        for (int i=0; i<t.length(); i++) {
            charCount[t[i]]++;
        }
        unordered_map<char, deque<int>> charToIndices;
        vector<bool> used(s.size(), false);
        int left = -1, cnt = 0,
            minLen = INT_MAX,
            minLeft = -1;
        for (int j=0; j<s.length(); j++) {
            char c = s[j];
            if (charCount.count(c)) {
                charToIndices[c].push_back(j);
                used[j] = true;
                if (left == -1)
                    left = j;
                if (charToIndices[c].size() == 1+charCount[c]) {
                    int k = charToIndices[c][0];
                    used[k] = false;
                    while (!used[left])
                        left++;
                    charToIndices[c].pop_front();
                } else {
                    cnt++;
                }
                if (cnt == t.length() && j-left+1 < minLen) {
                    minLen = j-left+1;
                    minLeft = left;
                }
            }
        }
        if (minLeft >= 0)
            return s.substr(minLeft, minLen);
        else
            return {};
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
