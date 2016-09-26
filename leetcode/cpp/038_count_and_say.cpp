#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    string countAndSay(int n) {
        string s = "1";
        while (n --> 1) {
            s = next(s);
        }
        return s;
    }
private:
    string next(string& s) {
        string result;
        int i = 0;
        while (i < s.length()) {
            int j = i + 1;
            while (j < s.length() && s[j] == s[j-1]) {
                j++;
            }
            int len = j - i;
            result += to_string(len);
            result += to_string(s[i] - '0');
            i = j;
        }
        return result;
    }
};

int main() {

    Solution solution;
    cout << solution.countAndSay(5) << endl;
}