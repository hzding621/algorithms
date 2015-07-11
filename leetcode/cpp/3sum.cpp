#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        if (nums.size() < 3)
            return ans;
        sort(nums.begin(), nums.end());
        for (int i=0; i<nums.size()-2; i++) {
            if (i > 0 && nums[i] == nums[i-1])
                continue;
            int sumTo = -nums[i];
            int m = i+1, n = nums.size()-1;
            while (m < n) {
                int tsum = nums[m] + nums[n];
                if (tsum == sumTo) {
                    ans.push_back(vector<int>{nums[i], nums[m], nums[n]});
                    do
                        m++;
                    while (m < n && nums[m] == nums[m-1]);
                }
                else if (tsum < sumTo)
                    m++;
                else
                    n--;
            }
        }
        return ans;
    }
};

void print(const vector<vector<int>>& vv) {
    for (const auto& v: vv) {
        for (int i: v)
            cout << i << " ";
        cout << endl;
    }
}

int main() {

    Solution sol;
    vector<int> v = {-1,0,1,2,-1,-4};
    auto ans = sol.threeSum(v);
    print(ans);
    return 0;
}
