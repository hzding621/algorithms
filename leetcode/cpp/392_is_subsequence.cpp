#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#include <set>

using namespace std;

class Solution {
public:
    bool isSubsequence(string s, string t) {
        int i = 0, j = 0;
        while (i < s.length() && j < t.length()) {
            if (s[i] == t[j]) { i++; }
            j++;
        }
        return i == s.length();
    }
};

class SubsequenceChecker {
public:
    SubsequenceChecker(string t) : _t(t) {
        for (int i = 0; i < t.length(); i++) {
            indicesByChar[t[i]-'a'].insert(i);
        }
    }

    bool isSubsequence(string s) {
        int currentIndex = -1;
        for (char c: s) {
            auto& indices = indicesByChar[c-'a'];
            auto first = indices.lower_bound(currentIndex);
            if (first == indices.end()) {
                return false;
            }
            currentIndex = *first;
        }
        return true;
    }

private:
    string _t;
    vector<set<int>> indicesByChar{26};
};

int main() {

    vector<pair<string, string>> tests = {
            {"abc", "ahbgdc"},
            {"axc", "ahbgdc"}
    };

//    Solution solution;
//    for (auto& test: tests) {
//        cout << solution.isSubsequence(test.first, test.second) << endl;
//    }

    vector<string> tests2 = {
            "abc",
            "axc",
            "ahbgdc",
            "ahdc",
            "hdc",
            "",
            "dc",
            "cd",
            "x"
    };
    SubsequenceChecker subsequenceChecker("ahbgdc");
    for (auto& test: tests2) {
        cout << subsequenceChecker.isSubsequence(test) << endl;
    }


    return 0;
}