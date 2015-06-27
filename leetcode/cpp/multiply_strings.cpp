#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    string multiply(string num1, string num2) {
        string res(num1.size() + num2.size() + 1, '0');
        reverse(num1.begin(), num1.end());
        reverse(num2.begin(), num2.end());
        for (int i=0; i<num1.size(); i++) {
            int n1 = num1[i] - '0';
            int carry = 0;
            for (int j=0; j<num2.size(); j++) {
                int n2 = num2[j] - '0';
                int current = res[i+j] - '0';
                int raw = n1 * n2 + carry + current;
                res[i+j] = raw % 10 + '0';
                carry = raw / 10;
            }
            if (carry > 0)
                res[i + num2.size()] = carry + '0';
        }
        reverse(res.begin(), res.end());
        // trim leading zeros
        int i;
        for (i = 0; res[i] == '0' && i < res.size(); i++)
            ;
        return i == res.size() ? "0" : res.substr(i, res.size() - i);
    }

};

int main() {

	Solution sol;
	cout << sol.multiply("123", "100") << endl;
}