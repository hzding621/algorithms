#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <set>
#include <climits>

using namespace std;

class Solution {
public:
    bool isReflected(vector<pair<int, int>>& points) {

        int leftBound = INT_MAX, rightBound = INT_MIN;
        unordered_map<int, unordered_set<int>> xToY;

        for (auto& p: points) {
            leftBound = min(leftBound, p.first);
            rightBound = max(rightBound, p.first);
            xToY[p.first].insert(p.second);
        }

        int sum = leftBound + rightBound;
        for (auto& p: points) {
            if (!xToY[sum - p.first].count(p.second)) {
                return false;
            }
        }
        return true;
    }
};

int main() {

    Solution solution;

    vector<pair<int,int>> vp = {
            {0, 0},
            {1, 0},
            {2, 0},
    };

    cout << solution.isReflected(vp) << endl;

    return 0;
}