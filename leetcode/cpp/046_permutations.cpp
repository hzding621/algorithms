#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> output;
        vector<bool> used(nums.size());
        vector<int> partial;
        search(output, nums, used, 0, partial);
        return output;
    }
private:
    void search(vector<vector<int>>& output,vector<int>& nums, vector<bool>& used, int usedCount, vector<int>& partial) {
        if (usedCount == nums.size()) {
            output.push_back(partial);
            return;
        }
        for (int i = 0; i < used.size(); i++) {
            if (!used[i]) {
                int d = nums[i];
                used[i] = true;
                partial.push_back(d);
                search(output, nums, used, usedCount + 1, partial);
                used[i] = false;
                partial.pop_back();
            }
        }
    }
};

int main() {

    Solution sol;
    vector<int> v = {1,2,3};
    auto vvi = sol.permute(v);
    for (auto& vi: vvi) {
        for (int i: vi) {
            cout << i << ' ';
        }
        cout << endl;
    }

    return 0;
}