#include <iostream>
#include <vector>
#include <set>

using namespace std;

class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        set<int> window;
        for (int i = 0; i < nums.size(); i++) {
            if (i - k > 0)
                window.erase(nums[i-k-1]);
            auto x = window.lower_bound(nums[i]-t);
            if (x != window.end() && *x - nums[i] <= t)
                return true;
            window.insert(nums[i]);
        }
        return false;
    }
};

int main() {
    Solution sol;
    vector<int> v = {2,5,7,9,3,6,4,0};
    cout << boolalpha;
    cout << sol.containsNearbyAlmostDuplicate(v, 1, 1) << endl;
    cout << sol.containsNearbyAlmostDuplicate(v, 1, 2) << endl;
    cout << sol.containsNearbyAlmostDuplicate(v, 2, 1) << endl;
}
