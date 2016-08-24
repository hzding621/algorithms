#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        vector<int> result;
        int carryover = 1;
        for (int i = digits.size() - 1; i >= 0; i--) {
            int d = digits[i];
            int s = d + carryover;
            if (s <= 9) {
                result.push_back(s);
                carryover = 0;
            } else {
                result.push_back(s - 10);
                carryover = 1;
            }
        }
        if (carryover) {
            result.push_back(carryover);
        }
        reverse(result.begin(), result.end());
        return result;
    }
};

int main() {

    Solution sol;
    vector<int> digits = {9,9,9,9};
    auto vi = sol.plusOne(digits);
    for (int i : vi) {
        cout << i << ' ';
    }
    cout << endl;

    return 0;
}