#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    string removeKdigits(string num, int k) {
        while (num != "0" && k) {
            num = removeOneDigit(num);
            k--;
        }
        return num;
    }

    string removeOneDigit(string& num) {
        if (num.length() <= 1) return "0";
        int i = 1;
        while (i < num.length() && num[i-1] <= num[i]) {
            i++;
        }
        // should remove character at i-1
        string result = num.substr(0, i-1) + num.substr(i);
        // remove all leading zeros
        i = 0;
        while (i < result.length() && result[i] == '0') {
            i++;
        }
        result = result.substr(i);
        if (result.empty()) return "0";
        else return result;
    }
};

int main() {

    Solution solution;
    vector<tuple<string, int, string>> testCases = {
            {"1432219", 3, "1219"},
            {"10200", 1, "200"},
            {"10", 2, "0"},
            {"54321", 2, "321"},
            {"453454345", 1, "43454345"},
            {"10000", 5, "0"},
            {"0", 1, "0"},
            {"223", 1, "22"},
            {"555", 0, "555"},
    };

    for (auto& test: testCases) {
        cout << "expected: " << get<2>(test)
             << " actual: " << solution.removeKdigits(get<0>(test), get<1>(test))
             << endl;
    }

    return 0;
}