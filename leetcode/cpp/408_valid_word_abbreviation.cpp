#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

class Solution {
public:
    bool validWordAbbreviation(string word, string abbr) {
        istringstream iss(abbr);
        int i = 0;
        while (i < word.length() && iss.peek() != EOF) {
            if (isdigit(iss.peek())) {
                // special case: numbers in abbr should not start with 0
                if (iss.peek() == '0') return false;

                int skip;
                iss >> skip;
                while (i < word.length() && skip-- > 0) {
                    i++;
                }
                if (skip > 0) return false;
            } else {
                char c;
                iss >> c;
                if (word[i] != c) break;
                i++;
            }
        }
        return iss.peek() == EOF && i == word.length();
    }
};

int main() {

    string s = "word";
    vector<string> valids = {"word", "1ord", "w1rd", "wo1d", "wor1", "2rd", "w2d", "wo2", "1o1d", "1or1", "w1r1", "1o2", "2r1", "3d", "w3", "4"};
    Solution solution;

    cout << boolalpha;
    for (auto& abbr: valids) {
        cout << solution.validWordAbbreviation(s, abbr) << endl;
    }

    cout << solution.validWordAbbreviation("a", "01") << endl;
}