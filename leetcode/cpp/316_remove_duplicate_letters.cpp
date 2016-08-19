#include <iostream>
#include <string>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
public:
    string removeDuplicateLetters(string s) {

        string output;
        unordered_map<char, int> lastPosition;
        unordered_map<char, bool> usedChars;
        for (int i = 0; i < s.length(); i++) {
            lastPosition[s[i]] = i;
        }
        int i = 0;
        while (!lastPosition.empty()) {
            int smallestLastIndex = s.length();
            for (auto& entry: lastPosition) {
                smallestLastIndex = min(smallestLastIndex, entry.second);
            }
            char smallestChar;
            int smallestCharIndex;

            for (; i <= smallestLastIndex; i++) {
                if (!usedChars[s[i]]) {
                    smallestChar = s[i];
                    smallestCharIndex = i;
                    break;
                }
            }

            for (; i <= smallestLastIndex; i++) {
                if (usedChars[s[i]]) {
                    continue;
                }
                if (s[i] < smallestChar) {
                    smallestChar = s[i];
                    smallestCharIndex = i;
                }
            }

            lastPosition.erase(smallestChar);
            usedChars[smallestChar] = true;
            output += smallestChar;
            i = smallestCharIndex + 1;
        }
        return output;
    }
};

int main() {

    Solution sol;
    string input = "baab";
    cout << sol.removeDuplicateLetters(input) << endl;

    return 0;
}