#include <iostream>

using namespace std;

class Solution {
public:
    int strStr(string haystack, string needle) {
        if (needle.empty()) return 0;
        for (int i = 0; i <= (int)haystack.size() - (int)needle.length(); i++) {
            if (doesMatch(haystack, i, needle)) return i;
        }
        return -1;
    }
private:
    bool doesMatch(string& haystack, int i, string& needle) {
        int j = 0;
        while (i < haystack.length() && j < needle.length()) {
            if (haystack[i] != needle[j]) return false;
            i++;
            j++;
        }
        return j == needle.length();
    }
};

int main() {

    Solution solution;
    cout << solution.strStr("haystack", "stack") << endl;
    cout << solution.strStr("haystack", "hstack") << endl;

}