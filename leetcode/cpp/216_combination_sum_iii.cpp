#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
vector<vector<int>> combinationSum3(int k, int n) {
    vector<vector<int>> resultBuilder;
    vector<int> combinationBuilder;
    combinationSumSearch(resultBuilder, combinationBuilder, k, n, 1);
    return resultBuilder;
}

private:
    
    void combinationSumSearch(vector<vector<int>>& resultBuilder, vector<int>& combinationBuilder, int currentK, int target, int startNumber) {
        if (currentK == 0) {
            if (target == 0) {
                resultBuilder.push_back(combinationBuilder);
            }
            return;
        }
        for (int s = startNumber; s <= 9 && target - s >= 0; s++) {
            combinationBuilder.push_back(s);
            combinationSumSearch(resultBuilder, combinationBuilder, currentK-1, target-s, s+1);
            combinationBuilder.pop_back();
        }
    }
};

int main() {

    int k = 3, n = 9;
    Solution sol;
    auto vvi = sol.combinationSum3(k, n);
    for (auto& vi: vvi) {
        for (int i: vi) {
            cout << i << " ";
        }
        cout << endl;
    }

}


