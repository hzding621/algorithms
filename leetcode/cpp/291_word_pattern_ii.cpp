#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
    bool wordPatternMatch(string pattern, string str) {
        unordered_map<char, string> charToStr;
        unordered_map<string, char> strToChar;
        return backtrack(pattern, str, 0, 0, charToStr, strToChar);
    }
private:

    bool backtrack(string& pattern, string& str, int i, int j,
                   unordered_map<char, string>& charToStr, unordered_map<string, char>& strToChar) {
        if (i == pattern.size() && j == str.size()) {
            return true;
        }
        if (i == pattern.size() || j == str.size()) {
            return false;
        }
        char c = pattern[i];
        if (charToStr.count(c)) {
            // look for charToStr[c]
            string s = charToStr[c];
            int jj = j, k = 0;
            while (jj < str.size() && k < s.size() && str[jj] == s[k]) {
                jj++; k++;
            }
            if (k == s.size() && backtrack(pattern, str, i+1, jj, charToStr, strToChar)) {
                // found charToStr[c] and continue
                return true;
            }
        } else {
            // find unused string for charToStr[c]
            for (int jj = j+1; jj <= str.size(); jj++) {
                string newString = str.substr(j, jj-j);
                if (!strToChar.count(newString)) {
                    charToStr[c] = newString;
                    strToChar[newString] = c;
                    if (backtrack(pattern, str, i+1, jj, charToStr, strToChar)) {
                        return true;
                    }
                    charToStr.erase(c);
                    strToChar.erase(newString);
                }
            }
        }
        return false;
    }
};

int main() {

    Solution sol;
    vector<pair<string,string>> testCases = {
            {"abab", "redblueredblue"},
            {"aaaa", "asdasdasdasd"},
            {"aabb", "xyzabcxzyabc"}
    };
    cout << boolalpha;

    for (auto& p: testCases) {
        cout << sol.wordPatternMatch(p.first, p.second) << endl;
    }

    return 0;
}