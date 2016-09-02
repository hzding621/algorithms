#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> output;
        if (digits.empty()) return output;
        string s = "";
        search(output, digits, 0, s);
        return output;
    }
private:
    void search(vector<string>& output, const string& digits, int i, string& partial) {
        if (i == digits.length()) {
            output.push_back(partial);
            return;
        }

        int digit = digits[i] - '0';
        for (char c: mapping[digit]) {
            partial.push_back(c);
            search(output, digits, i + 1, partial);
            partial.pop_back();
        }
    }
private:

    const vector<string> mapping = {
            " ",
            "",     "abc",  "def",
            "ghi",  "jkl",  "mno",
            "pqrs", "tuv",  "wxyz"
    };
};

int main() {

    Solution sol;
    string digits = "23";
    auto vs = sol.letterCombinations(digits);
    for (auto& s: vs) {
        cout << s << endl;
    }

    return 0;
}