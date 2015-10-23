class Solution {
public:
    string addBinary(string a, string b) {
        int n = a.length(), m = b.length();
        int i = 0, j = 0;
        string s;
        bool carryover = 0;
        while (i < n && j < m) {
            bool c = a[n-1-i]-'0', d = b[m-1-j]-'0';
            if (c + d + carryover == 0) {
                s.push_back('0');
                carryover = 0;
            } else if (c + d + carryover == 1) {
                s.push_back('1');
                carryover = 0;
            } else if (c + d + carryover == 2) {
                s.push_back('0');
                carryover = 1;
            } else {
                s.push_back('1');
                carryover = 1;
            }
            i++; 
            j++;
        }
        while (i < n) {
            bool c = a[n-1-i]-'0';
            if (c + carryover == 0) {
                s.push_back('0');
                carryover = 0;
            } else if (c + carryover == 1){
                s.push_back('1');
                carryover = 0;
            } else {
                s.push_back('0');
                carryover = 1;
            }
            i++;
        }
        while (j < m) {
            bool c = b[m-1-j]-'0';
            if (c + carryover == 0) {
                s.push_back('0');
                carryover = 0;
            } else if (c + carryover == 1){
                s.push_back('1');
                carryover = 0;
            } else {
                s.push_back('0');
                carryover = 1;
            }
            j++;
        }
        if (carryover == 1)
            s.push_back('1');
        reverse(s.begin(), s.end());
        return s;
    }
};