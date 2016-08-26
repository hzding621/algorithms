#include <iostream>
#include <string>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstringKDistinct(string s, int k) {
        if (k == 0) {
            return 0;
        }
        unordered_map<char, int> charLastAppearPos;
        int i = 0, j = 0, maxLen = 0;
        while (j < s.length()) {
            char c = s[j];
            if (!charLastAppearPos.count(c) && charLastAppearPos.size() == k) {
                while (charLastAppearPos[s[i]] != i) {
                    i++;
                }
                charLastAppearPos.erase(s[i]);
                i++;
            } 
            charLastAppearPos[s[j]] = j;
            maxLen = max(maxLen, j - i + 1);
            j++;
        }
        return maxLen;
    }
};

int main() {

    Solution sol;
    cout << sol.lengthOfLongestSubstringKDistinct("", 3) << endl;

    return 0;
}