#include <iostream>
#include <string>
#include <sstream>

using namespace std;

int main() {
    int n;
    cin >> n;
    while (n > 0) {
        n--;
        string s, t;
        cin >> s >> t;
        int i = 0;
        stringstream ss;
        int co = 0;
        while (i < s.length() && i < t.length()) {
            int a = s[i]-'0', b = t[i]-'0';
            if (a + b + co >= 10) {
                ss << a + b + co -10;
                co = 1;
            } else {
                ss << a + b + co;
                co = 0;
            }
            i++;
        }
        while (i < s.length()) {
            int a = s[i]-'0';
            if (a + co >= 10) {
                ss << a + co - 10;
                co = 1;
            } else {
                ss << a + co;
                co = 0;
            }
            i++;
        }
        while (i < t.length()) {
            int a = t[i]-'0';
            if (a + co >= 10) {
                ss << a + co - 10;
                co = 1;
            } else {
                ss << a + co;
                co = 0;
            }
            i++;
        }
        if (co == 1)
            ss << '1';
        string o = ss.str();
        i = 0;
        while (o[i] =='0')
            i++;
        cout << o.substr(i) << endl;

    }
}
