#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    vector<string> generateAbbreviations(string word) {
        vector<string> output;
        string s = "";
        search(output, word, s, 0, false);
        return output;
    }
private:
    void search(vector<string>& output, string& word, string& stringBuilder, int currentIndex, bool charOnly) {
        // at each character,
        //      I can either record the character and increment by one
        //      or I can create an abbreviation of up to the last character
        if (currentIndex == word.size()) {
            output.push_back(stringBuilder);
            return;
        }
        char c = word[currentIndex];
        stringBuilder.push_back(c);
        search(output, word, stringBuilder, currentIndex + 1, false);
        stringBuilder.pop_back();
        if (charOnly) {
            return;
        }
        for (int len = 1; currentIndex + len <= word.size(); len++) {
            string number = to_string(len);
            for (char c: number)
                stringBuilder.push_back(c);
            search(output, word, stringBuilder, currentIndex + len, true);
            for (int k = 0; k < number.size(); k++)
                stringBuilder.pop_back();
        }
    }
};

int main() {

    string word = "word";
    Solution sol;
    auto vs = sol.generateAbbreviations(word);
    for (string& s: vs) {
        cout << s << endl;
    }

    return 0;
}