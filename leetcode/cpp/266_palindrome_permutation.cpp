#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    bool canPermutePalindrome(string s) {

        unordered_map<char, int> charCounter;
        for (char c: s) {
            charCounter[c]++;
        }

        bool oddOccured = false;
        for (auto& entry: charCounter) {
            if (entry.second % 2) {
                if (oddOccured) return false;
                oddOccured = true;
            }
        }
        return true;
    }
};

int main() {

    Solution solution;

    vector<string> cases = {
            "code",
            "aab",
            "carerac"
    };

    for (auto& s: cases) {
        cout << solution.canPermutePalindrome(s) << endl;
    }

    return 0;
}