#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>

using namespace std;

class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int a = INT_MAX, b = INT_MAX;
        for (int i: nums) {
            if (i <= a) {
                a = i;
            } else if (i <= b) {
                b = i;
            } else {
                return true;
            }
        }
        return false;
    }
};

int main() {

    Solution sol;
    vector<int> v = {-10, 1, 2, 3, -7};
    cout << sol.increasingTriplet(v) << endl;

    return 0;
}