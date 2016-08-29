#include <iostream>
#include <string>
#include <stdexcept>
#include <algorithm>

using namespace std;

class Solution {
public:
    int strobogrammaticInRange(string low, string high) {
        int len1 = low.length(), len2 = high.length();
        if (len1 > len2) return 0;
        if (len1 == len2 && !lessEqual(low, high)) return 0;
        bool highIsSbt = isSbtString(high, len2);
        int lowToMax = countToMax(low);
        int highToMax = countToMax(high);
        int sum = 0;
        for (int len = len1 + 1; len <= len2; len++) {
            sum += countAllOfLength(len);
        }
        return lowToMax + sum - highToMax + highIsSbt;
    }
private:
    int nextStbInt[9] = {1,6,6,6,6,6,8,8,9};
    int stbIntGe[10] = {5,4,3,3,3,3,3,2,2,1};
    int stbSymIntGe[10] = {3,2,1,1,1,1,1,1,1,0};
    char mirror[11] = "01----9-86";

    int countToMax(string& lower) {
        int len = lower.length();
        int sumCount = 0;

        bool prefixSbt = true, oddLength = len % 2;
        for (int i = 0; i < len/2; i++) {
            int digit = lower[i] - '0';
            if (digit < 9) {
                sumCount += countPartial(nextStbInt[digit], len/2 - i, oddLength);
            }
            if (!isSbtInt(digit)) {
                prefixSbt = false;
                break;
            }
        }

        // consider using the prefix 
        if (prefixSbt) {
            string correctSuffix = findMirrorSuffix(lower, len);
            string actualSuffix = lower.substr((len+1)/2);

            int midDigit = lower[len/2]-'0';
            if (lessEqual(actualSuffix, correctSuffix)) {
                sumCount += oddLength ? stbSymIntGe[midDigit] : 1;
            } else if (oddLength && midDigit < 9) {
                sumCount += stbSymIntGe[midDigit+1];
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

    int countPartial(int startDigit, int prefixLength, bool oddLength) {
        int times = oddLength ? stbSymIntGe[0] : 1;
        times *= stbIntGe[startDigit];
        for (int i = 1; i < prefixLength; i++) {
            times *= stbIntGe[0];
        }
        return times;
    }

    bool isSbtInt(int i) {
        return i == 1 || i == 6 || i == 8 || i == 9 || i == 0;
    }

    bool isSbtSymInt(int i) {
        return i == 1 || i == 8 ||  i == 0;
    }

    string findMirrorSuffix(string& s, int len) {
        string ret;
        for (int i = len/2-1; i >= 0; i--) {
            ret.push_back(mirror[s[i] - '0']);
        }
        return ret;
    }

    bool isSbtString(string& s, int len) {
        if (len % 2 && !isSbtSymInt(s[len/2]-'0')) return false;
        string correctSuffix = findMirrorSuffix(s, len);
        string actualSuffix = s.substr((len+1)/2);
        return correctSuffix == actualSuffix; 
    }

    bool lessEqual(string& a, string& b) {
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
};

int main() {

    Solution sol;
    cout << sol.strobogrammaticInRange("0", "100") << endl;

    return 0;
}