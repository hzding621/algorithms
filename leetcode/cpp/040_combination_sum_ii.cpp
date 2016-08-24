#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
    sort(candidates.begin(), candidates.end());
    vector<vector<int>> resultBuilder;
    vector<int> combinationBuilder;
    combinationSumSearch(candidates, target, 0, combinationBuilder, resultBuilder);
    return resultBuilder;
}
private:
    void combinationSumSearch(const vector<int>& candidates, const int target, const int candidatesStartIndex, vector<int>& combinationHelper, vector<vector<int>>& resultBuilder) {
        if (target == 0) {
            resultBuilder.push_back(combinationHelper);
            return;
        }
        for (int i = candidatesStartIndex; i < candidates.size() && target >= candidates[i]; i++) {
            if (i > candidatesStartIndex && candidates[i] == candidates[i-1]) {
                continue;
            }
            combinationHelper.push_back(candidates[i]);
            combinationSumSearch(candidates, target - candidates[i], i + 1, combinationHelper, resultBuilder);
            combinationHelper.pop_back();
        };
    }
};

int main() {

    Solution sol;
    vector<int> v = {10, 1, 2, 7, 6, 1, 5}; // 1,1,2,5,6,7,10
    int target = 8;
    // 3 + 4 + 5
    auto vvi = sol.combinationSum2(v, target);
    for (auto& vi: vvi) {
    for (int i : vi) {
        cout << i << " ";
        }
        cout << endl;
    }   

    return 0;
}