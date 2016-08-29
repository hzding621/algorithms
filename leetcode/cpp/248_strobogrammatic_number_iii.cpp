#include <iostream>
#include <string>
#include <stdexcept>
#include <algorithm>

using namespace std;

class Solution {
public:
    int strobogrammaticInRange(string low, string high) {
        // 1, 6, 8, 9, 0
        int len1 = low.length(), len2 = high.length();
        if (len1 > len2) return 0;
        if (len1 == len2 && !leSameLength(low, high)) return 0;
        string highPlusOne = plusOne(high);
        int lowToMax = countToMax(low);
        int highToMax = highPlusOne.size() ? countToMax(highPlusOne) : 0;
        int sum = 0;
        for (int len = len1 + 1; len <= len2; len++) {
            sum += countAllOfLength(len);
        }
        return lowToMax + sum - highToMax;
    }

private:

    int countToMax(string lower) {
        // try from middle to get to next valid stro
        int len = lower.length();
        int sumCount = 0;

        for (int i = 0; i < len/2; i++) {
            int digit = lower[i]-'0';
            if (digit < 9) {
                sumCount += countPartial(nextInt[digit], len/2 - i, len % 2);
            }
            if (!isStro(lower[i])) {
                break;
            }
        }

        if (prefixIsStro(lower)) {
            string correctSuf = findMatchSuffix(lower);
            string actualSuf = lower.substr((len+1)/2);

            if (leSameLength(actualSuf, correctSuf)) {
                sumCount += (len % 2) ? geSingle[lower[len/2]-'0'] : 1;
            } else {
                sumCount += (len % 2) ? (lower[len/2] == '9' ? 0 : geSingle[lower[len/2]-'0'+1]) : 0;
            }
        }
        return sumCount;
    }

    int countAllOfLength(int n) {
        if (n == 1) throw invalid_argument("countAllOfLength: n=1");
        if (n == 2) return 4;
        int times = n % 2 ? 3 : 1;
        for (int i = 0; i < n/2; i++) {
            if (i == 0) times *= 4;
            else times *= 5;
        }
        return times;
    }

    int nextInt[10] = {1,6,6,6,6,6,8,8,9};
    int ge[11] = {5,4,3,3,3,3,3,2,2,1,0};
    int geSingle[11] = {3,2,1,1,1,1,1,1,1,0,0}; 
    char match[11] = "01----9-86";

    int countPartial(int startDigit, int prefixLength, bool odd) {
        int times = odd ? 3 : 1;
        times *= ge[startDigit];
        for (int i = 2; i <= prefixLength; i++) {
            times *= ge[0];
        }
        return times;
    }

    bool prefixIsStro(string& s) {
        int len = s.length();
        for (int i = 0; i < len/2; i++) {
            if (!isStro(s[i])) 
                return false;
        }
        return true;
    }

    string findMatchSuffix(string& s) {
        string r;
        int len = s.length();
        for (int i = len/2-1; i >= 0; i--) {
            r.push_back(match[s[i]-'0']);
        }
        return r;
    }

    bool leSameLength(string& a, string& b) {
        if (a.length() != b.length()) {
            throw invalid_argument("Strings of unequal length!");
        }
        int i = 0;
        while (i < a.length()) {
            if (a[i] < b[i]) return true;
            if (a[i] > b[i]) return false;
            i++;
        }
        return true;
    }

    string plusOne(string& s) {
        // return "" if s is all nine
        string ret;
        int carryover = 1;
        for (int i = s.length() - 1; i >= 0; i--) {
            int digit = s[i] - '0' + carryover;
            if (digit >= 10) {
                digit -= 10;
                carryover = 1;
            } else {
                carryover = 0;
            }
            ret.push_back('0' + digit);
        }
        if (carryover) return "";
        reverse(ret.begin(), ret.end());
        return ret;
    }

    bool isStro(char c) {
        return (c == '0' || c == '1' || c == '6' || c == '8' || c == '9');
    }
};

int main() {

    return 0;
}