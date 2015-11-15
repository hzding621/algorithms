#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {

    string s;
    int counts[26];
    fill_n(counts, 26, 0);
    for (int i=0; i<4; i++) {
        getline(cin, s);
        for (int i=0; i<s.length(); i++) {
            if (s[i] < 'A' || s[i] > 'Z')
                continue;
            counts[s[i]-'A']++;
        }
    }
    int height = 0;
    for (int i=0; i<26; i++) {
        height = max(height, counts[i]);
    }
    while (height > 0) {
        for (int i=0; i<26; i++) {
            if (counts[i]-height>=0)
                cout << '*';
            else
                cout << ' ';
            if (i < 25)
                cout << ' ';
        }
        cout << endl;
        height--;
    }
    for (int i=0; i<26; i++) {
        cout << (char)('A'+i);
        if (i < 25)
            cout << ' ';
    }
    cout << endl;

    return 0;
}
