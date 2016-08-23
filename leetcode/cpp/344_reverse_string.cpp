#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    string reverseString(string s) {
        int i = 0, j = s.length() - 1;
        while (i + 1 <= j) {
            char c = s[i];
            s[i] = s[j];
            s[j] = c;
        }
        return s;
    }
};

int main() {

    return 0;
}