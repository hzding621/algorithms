#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
        vector<string> restoreIpAddresses(string s) {
        vector<string> ans;
        continuation(ans, "", s, 0, 4);
        return ans;
    }

    void continuation(vector<string>& ans, string prefix, const string& s, int start, int count) {
        if (start == s.length() && count == 0) {
            ans.push_back(prefix);
            return;
        }

        if (start == s.length() || count == 0)
            return;

        if (prefix.length() > 0)
            prefix += ".";

        if (s.length() - start >= 1)
            continuation(ans, prefix + s.substr(start, 1), s, start+1, count-1);

        if (s.length() - start >= 2 && s[start] != '0')
            continuation(ans, prefix + s.substr(start, 2), s, start+2, count-1);

        if (s.length() - start >= 3 && is_valid(s, start))
            continuation(ans, prefix + s.substr(start, 3), s, start+3, count-1);
    }

    bool is_valid(const string& s, int start) {
        string ss = s.substr(start, 3);
        int i = stol(ss);
        return 100 <= i && i <= 255;
    }
};

void print(const vector<string>& v) {
    for (const auto& s: v)
        cout << s << endl;
}

int main() {

    Solution sol;
    print(sol.restoreIpAddresses("2552552552"));
}