#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <set>
#include <climits>

using namespace std;

class Solution {
public:
    vector<string> generatePossibleNextMoves(string s) {
        vector<string> answers;
        for (int i = 1; i < s.length(); i++) {
            if (s[i] == s[i-1] && s[i] == '+') {
                s[i] = s[i-1] = '-';
                answers.push_back(s);
                s[i] = s[i-1] = '+';

            }
        }
        return answers;
    }
};

int main() {


    string s = "++++";
    Solution solution;

    auto vs = solution.generatePossibleNextMoves(s);
    for (auto& s: vs) {
        cout << s << endl;
    }

    return 0;
}