#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>

using namespace std;


class Solution {
public:
    vector<vector<int>> palindromePairs(vector<string>& words) {
        if (words.size() == 0)
            return {};

        unordered_map<string, int> reversedWords;
        for (int i = 0; i < words.size(); i++) {
            string s = words[i];
            reverse(s.begin(), s.end());
            reversedWords[s] = i;
        }

        vector<vector<int>> result;

        for (int i = 0; i < words.size(); i++) {
            // for each prefix, including empty string
            string s = words[i];
            for (int j = 0; j <= s.size(); j++) {
                string prefix = s.substr(0, j);
                if (reversedWords.count(prefix)) {
                    int k = reversedWords[prefix];
                    if (i != k  && isPalindrome(s, j, s.size()-1)) {
                        result.push_back({i, reversedWords[prefix]});
                    }
                }
            }

            // for each suffix, including empty string
            for (int j = 1; j <= s.size(); j++) {
                string suffix = s.substr(j);
                if (reversedWords.count(suffix)) {
                    int k = reversedWords[suffix];
                    if (i != k && isPalindrome(s, 0, j-1)) {
                        result.push_back({reversedWords[suffix], i});
                    }
                }
            }
        }

        return result;
    }
private:

    bool isPalindrome(const string& s, int startIndex, int endIndex) {
        while (startIndex <= endIndex) {
            if (s[startIndex] != s[endIndex]) {
                return false;
            }
            startIndex++;
            endIndex--;
        }
        return true;
    }
};

int main() {

    vector<string> words = {"a", ""};
    Solution sol;
    auto vvi = sol.palindromePairs(words);
    for (auto& p: vvi) {
        cout << p[0] << "," << p[1] << endl;
    }

    return 0;
}