#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<vector<string>> groupStrings(vector<string>& strings) {
        unordered_map<string, vector<string>> grouping;
        for (int i = 0; i < strings.size(); i++) {
            string& s = strings[i];
            string indexString;
            for (int j = 1; j < s.length(); j++) {
                int diff = (s[j] - s[j-1] + 26) % 26;
                indexString.push_back('a' + diff);
            }
            grouping[indexString].push_back(s);
        }

        vector<vector<string>> output;
        for (auto& e: grouping) {
            output.push_back(e.second);
        }
        return output;
    }
};

int main() {

    vector<string> vs = {"abc", "bcd", "acef", "xyz", "az", "ba", "a", "z"};
    Solution solution;
    auto vvs = solution.groupStrings(vs);
    for (auto& vs: vvs) {
        for (auto& s: vs) {
            cout << s << " ";
        }
        cout << endl;
    }

    return 0;
}