class Solution {
public:
    bool isNumber(string s) {
        int state = 0;
        // 0: seeking num or . or - or +
        // 1: seeking e/.
        // 2: only whitespace or num or e
        // 3: only whitespaces
        // 4: must at least one num for .
        // 5: must at least one num or . for +-
        // 6: must at least one num for e
        // 7: only whitespace or num
        // 8: dead state
        for (int i=0; i<s.length(); i++) {
            char c = s[i];
            if (state == 0) {
                if (c == ' ')
                    continue;
                else if (c >= '0' && c <= '9')
                    state = 1;
                else if (c == '.')
                    state = 4;
                else if (c == '+' || c == '-')
                    state = 5;
                else
                    state = 8;
            } else if (state == 1) {
                if (c == ' ') {
                    state = 3;
                } else if (c == '.') {
                    state = 2;
                } else if (c == 'e') {
                    state = 6;  
                } else if (c >= '0' && c <= '9') {
                    continue;
                } else
                    state = 8;
            } else if (state == 4) {
                if (c >= '0' && c <= '9') {
                    state = 2;
                } else 
                    state = 8;
            } else if (state == 2) {
                if (c == ' ') {
                    state = 3;
                } else if (c >= '0' && c <= '9') {
                    continue;
                } else if (c == 'e')
                    state = 6;
                else
                    state = 8;
            } else if (state == 3) {
                if (c == ' ')
                    continue;
                else
                    state = 8;
            } else if (state == 5) {
                if (c >= '0' && c <= '9')
                    state = 1;
                else if (c == '.')
                    state = 4;
                else
                    state = 8;
            } else if (state == 6) {
                if (c >= '0' && c <= '9')
                    state = 7;
                else if (c == '-' || c == '+')
                    state = 4;
                else
                    state = 8;
            } else if (state == 7) {
                 if (c == ' ') {
                    state = 3;
                } else if (c >= '0' && c <= '9') 
                    continue;
                else
                    state = 8;
            } else if (state == 8) {
                continue;
            }
        }
        return state == 1 || state == 2 || state == 3 || state == 5 || state == 7;
    }
};