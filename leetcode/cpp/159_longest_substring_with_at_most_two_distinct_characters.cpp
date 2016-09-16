#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstringTwoDistinct(string s) {
        unordered_map<char, int> lastIndex;
        int j = 0, maxLen = 0;
        for (int i = 0; i < s.length(); i++) {
            if (lastIndex.size() == 2 && !lastIndex.count(s[i])) {
                while (lastIndex[s[j]] != j) {
                    j++;
                }
                lastIndex.erase(s[j]);
                j++;
            }
            lastIndex[s[i]] = i;
            maxLen = max(maxLen, i - j + 1);
        }
        return maxLen;
    }
};

int main() {

    Solution sol;

    vector<string> ss = {
            "aabbccc",
            "abaccc"
    };
    for (string& s: ss)
        cout << sol.lengthOfLongestSubstringTwoDistinct(s) << endl;
}