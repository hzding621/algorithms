#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        vector<int> lettersCount(26);
        for (char c: ransomNote) {
            lettersCount[c - 'a']++;
        }
        for (char c: magazine) {
            lettersCount[c - 'a']--;
        }
        for (int i: lettersCount) {
            if (i > 0) {
                return false;
            }
        }
        return true;
    }
};

int main() {

    return 0;
}