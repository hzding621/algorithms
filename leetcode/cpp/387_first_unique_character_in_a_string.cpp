#include <iostream>
#include <string>
#include <unordered_map>
#include <list>
#include <vector>

using namespace std;

class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<char,int> charCount;
        for (char c: s) {
            charCount[c]++;
        }
        for (int i = 0; i < s.length(); i++) {
            if (charCount[s[i]] == 1) {
                return i;
            }
        }
        return -1;
    }
};

int main() {

    vector<string> testCases = {
        "leetcode",
        "loveleetcode",
        "aabbccdd"
    };

    for (string& s: testCases) {
        cout << Solution().firstUniqChar(s) << endl;
    }


    return 0;
}