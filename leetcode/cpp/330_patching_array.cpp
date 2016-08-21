#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int minPatches(vector<int>& nums, int n) {

        long canBuildUpTo = 0, numberInserted = 0, i = 0;
        while (canBuildUpTo < n) {
            if (i < nums.size() && nums[i] <= canBuildUpTo + 1) {
                // either: the next number is exactly 1 + what currently can be built
                // or: the next number can already be built
                // then: expand the range of what can be built
                canBuildUpTo += nums[i];
                i++;
            } else {
                // the number is beyond 1 + what can be built
                // or ran out of input numbers
                // then: must add 1 + waht currently can be built
                numberInserted++;
                canBuildUpTo += (canBuildUpTo + 1);
            }
        }
        return numberInserted;
    }
};

int main() {

    vector<int> v = {};
    Solution sol;
    cout << sol.minPatches(v, 7) << endl;

    return 0;
}