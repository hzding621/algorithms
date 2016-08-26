#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    void reverseWords(string &s) {
        // first reverse the string
        reversePart(s, 0, s.length()-1);

        // then reverse each word
        int i = 0, j = 0;
        while (j < s.length()) {
            while (j < s.length() && s[j] != ' ') {
                j++;
            }
            j--;
            reversePart(s, i, j);
            i = j = j + 2;
        }
    }
private:

    void reversePart(string&s, int startIndex, int endIndex) {
        int i = startIndex, j = endIndex;
        while (i <= j) {
            char c = s[i];
            s[i] = s[j];
            s[j] = c;
            i++;
            j--;
        }
    }
};

int main() {

    string s = "the sky is blue";
    Solution sol;
    sol.reverseWords(s);
    cout << s << endl;

    return 0;
}