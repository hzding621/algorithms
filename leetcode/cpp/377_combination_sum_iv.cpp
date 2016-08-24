#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        
        vector<int> memoize(target+1);
        memoize[0] = 1;
        for (int i = 1; i <= target; i++) {
            for (int j = 0; j < nums.size(); j++) {
                if (i - nums[j] >= 0) {
                    memoize[i] += memoize[i - nums[j]];
                }
            }
        }
        return memoize[target];
    }
};

int main() {

    vector<int> v = {1,2,3};
    int target = 4;

    Solution sol;
    cout << sol.combinationSum4(v, 4) << endl;

    return 0;
}