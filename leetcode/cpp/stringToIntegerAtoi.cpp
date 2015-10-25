class Solution {
public:
    int myAtoi(string str) {
        int n = str.length();
        int i = 0;
        while (i < n && str[i] == ' ')
            i++;
        bool pos = true;
        long long num = 0;
        if (i < n) {
            if (str[i] == '-')
                pos = false;
            if (str[i] == '+' || str[i] == '-')
                i++;
            while (str[i] <= '9' && str[i] >= '0') {
                num = num * 10 + (str[i]-'0');
                if (pos && num > INT_MAX) return INT_MAX;
                if (!pos && (-num) < INT_MIN) return INT_MIN;
                i++;
            }
        }
        return pos?num:-num;
    }
};