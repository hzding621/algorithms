#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size();
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());

        unordered_map<int, vector<pair<int,int>>> table;
        for (int i = 0; i < n; i++) {
            for (int j = i+1; j < n; j++) {
                int key = nums[i] + nums[j];
                table[key].emplace_back(i, j);
            }
        }

        for (int i=0; i<n-3; i++) {
            if (i == 0 || nums[i] != nums[i-1]) {
                for (int j = i+1; j < n-2; j++) {
                    if (j == i+1 || nums[j] != nums[j-1]) {
                        if (table.find(target-nums[i]-nums[j]) != table.end()) {
                            vector<pair<int,int>>& sum2 = table[target-nums[i]-nums[j]];
                            bool found = false;
                            for (int k = 0; k < sum2.size(); k++) {
                                if (sum2[k].first > j && (!found || res[res.size()-1][2] != nums[sum2[k].first])) {
                                    res.push_back(vector<int>{nums[i], nums[j], nums[sum2[k].first], nums[sum2[k].second]});
                                    found = true;
                                }
                            }
                        }
                    }
                }
            }
        }
        return res;


    }
};

int main() {

        return 0;
}
