#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <iterator>

using namespace std;

class Solution {
public:
    vector<string> wordBreak(string s, unordered_set<string>& wordDict) {
        unordered_map<int, vector<string>> cache;
        return backtrack(wordDict, s, 0, cache);
    }
private:
    vector<string> backtrack(unordered_set<string> &dict, const string &s,
                             int i,
                             unordered_map<int, vector<string>>& cache) {
        vector<string> output;
        if (i == s.length()) {
            output.push_back("");
            return output;
        }
        if (cache.count(i)) {
            return cache[i];
        }
        for (int len = 1; i + len <= s.length(); len++) {
            string nextToken = s.substr(i, len);
            if (dict.count(nextToken)) {
                auto forwardResult = backtrack(dict, s, i + len, cache);
                for (auto& s: forwardResult) {
                    if (s.length()) {
                        output.push_back(nextToken + " " + s);
                    } else {
                        output.push_back(nextToken);
                    }
                }
            }
        }
        cache[i] = output;
        return output;
    }
};

int main() {

    string s = "catsanddog";
    unordered_set<string> dict = {"cat", "cats", "and", "sand", "dog"};
    Solution sol;
    auto vs = sol.wordBreak(s, dict);
    for (auto& s: vs) {
        cout << s << endl;
    }

    return 0;
}