#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> getModifiedArray(int length, vector<vector<int>>& updates) {
        vector<int> result(length);
        for (auto& vi: updates) {
            result[vi[0]] += vi[2];
            if (vi[1] < length - 1) {
                result[vi[1]+1] -= vi[2];
            }
        }
        int currentValue = 0;
        for (int i = 0; i < length; i++) {
            currentValue += result[i];
            result[i] = currentValue;
        }
        return result;
    }
};

int main() {

    int length = 5;
    vector<vector<int>> v = {
        {1, 3, 2},
        {2, 4, 3},
        {0, 2, -2}
    };
    Solution sol;
    auto vi = sol.getModifiedArray(length, v);
    for (int i: vi) {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}