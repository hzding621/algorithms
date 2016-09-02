#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> getFactors(int n) {
        vector<vector<int>> result;
        vector<int> partial;
        search(result, partial, n, 2);
        result.pop_back(); // factor should be less than n, the largest element is always n = n
        return result;
    }
private:
    void search(vector<vector<int>>& result, vector<int>& partial, int n, int factorLowerBound) {
        if (n == 1) {
            result.push_back(partial);
            return;
        }
        for (int p = factorLowerBound; p <= n; p++) {
            if (n % p == 0) {
                // p is a factor
                partial.push_back(p);
                search(result, partial, n / p, p);
                partial.pop_back();
            }
        }
    }
};

int main() {

    Solution sol;
    auto vvi = sol.getFactors(37);
    for (auto& vi: vvi) {
        for (int i: vi) {
            cout << i << " ";
        }
        cout << endl;
    }

    return 0;
}