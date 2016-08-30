#include <iostream>
#include <sstream>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
    bool wordPattern(string pattern, string str) {
        unordered_map<char, string> charToStr;
        unordered_map<string, char> strToChar;
        istringstream iss(str);
        string word;
        for (char c: pattern) {
            if (!getline(iss, word, ' ')) {
                return false;
            }
            if (charToStr.count(c) && charToStr[c] != word) {
                return false;
            }
            if (strToChar.count(word) && strToChar[word] != c) {
                return false;
            }
            if (!charToStr.count(c) && !strToChar.count(word)) {
                charToStr[c] = word;
                strToChar[word] = c;
            }
        }
        return !getline(iss, word, ' ');
    }
};

int main() {

    Solution sol;
    vector<pair<string, string>> testCases = {
            {"abba", "dog cat cat dog"},
            {"abba", "dog cat cat fish"},
            {"aaaa", "dog cat cat dog"},
            {"abba", "dog dog dog dog"}
    };
    cout << boolalpha;
    for (auto& p: testCases) {
        cout << sol.wordPattern(p.first, p.second) << endl;
    }
    return 0;
}