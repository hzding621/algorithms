#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<string> findStrobogrammatic(int n) {

        vector<string> result;
        string partial;
        findPrefixes(result, n/2, partial, n % 2);

        for (string& p: result) {
            for (int i = n/2-1; i >=0; i--) {
                p.push_back(getMatchingDigit(p[i]));
            }
        }

        return result;
    }
private:
    void findPrefixes(vector<string>& output, int prefixLength, string& partial, bool odd) {
        if (partial.length() == prefixLength) {
            if (!odd) {
                output.push_back(partial);
            } else {
                output.push_back(partial + "0");
                output.push_back(partial + "1");
                output.push_back(partial + "8");
            }
            return;
        }
        for (int i: strobogrammaticDigits) {
            if (i == 0 && partial.length() == 0) continue; // cannot start with 0
            partial.push_back('0' + i);
            findPrefixes(output, prefixLength, partial, odd);
            partial.pop_back();
        }

    }
    vector<int> strobogrammaticDigits = {0,1,6,8,9};

    char getMatchingDigit(char c) {
        switch (c) {
            case '0':
                return '0';
            case '1':
                return '1';
            case '6':
                return '9';
            case '8':
                return '8';
            case '9':
                return '6';
            default:
                throw invalid_argument("Not a valid strobogrammatric digit!");
        }
    }
};

int main() {

    Solution sol;
    auto vs = sol.findStrobogrammatic(3);
    for (auto& s: vs) {
        cout << s << endl;
    }


    return 0;
}