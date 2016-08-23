#include <iostream>
#include <string>
#include <vector>

using namespace std; 

class Solution {
public:
    string reverseVowels(string s) {
        vector<int> vowelIndices;
        for (int i = 0; i < s.length(); i++) {
            if (isVowel(s[i])) {
                vowelIndices.push_back(i);
            }
        }
        int i = 0, j = vowelIndices.size() - 1;
        while (i + 1 <= j) {
            char c = s[vowelIndices[j]];
            s[vowelIndices[j]] = s[vowelIndices[i]];
            s[vowelIndices[i]] = c;
            i++;
            j--;
        }
        return s;
    }
private:
    bool isVowel(char c) {
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u'
            || c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U';
    }
};

int main() {

    string s = "hellO";
    Solution sol;
    cout << sol.reverseVowels(s) << endl;

}