class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        bool neg = (numerator > 0 && denominator < 0) || (numerator < 0 && denominator > 0);
        long lnumerator = abs((long)numerator);
        long ldenominator = abs((long)denominator);
        long n = lnumerator / ldenominator,
            r = lnumerator % ldenominator;
        string s = (neg ? "-" : "") + to_string(n);
        if (r == 0)
            return s;
        unordered_map<long, int> remToInd;
        s.push_back('.');
        r *= 10; n = r / ldenominator;
        while (r && !remToInd.count(r)) {
            remToInd[r]=s.length();
            s.push_back(n+'0');
            r = r % ldenominator * 10;
            n = r / ldenominator;
        }
        if (r) {
            s = s.substr(0, remToInd[r]) + "(" + s.substr(remToInd[r]) + ")";
        }
        return s;
    }
};