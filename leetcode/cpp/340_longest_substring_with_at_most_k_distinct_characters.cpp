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
        unordered_map<char, int> lastAppearIndex;
        int i = 0, j = 0, maxLen = 0; // two pointers
        while (j < s.length()) {
            char c = s[j];

            // read a new character, but current seen characters have reached k
            if (!lastAppearIndex.count(c) && lastAppearIndex.size() == k) {
                while (lastAppearIndex[s[i]] != i) {
                    i++;
                }

                // i is at the last appearing position of s[i]
                lastAppearIndex.erase(s[i]);
                i++;
            }
            lastAppearIndex[s[j]] = j;
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