#include <algorithm>
#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <map>
#include <set>
#include <utility>
#include <string>
#include <sstream>
#include <climits>

using namespace std;

class Solution {
public:
    int splitArray(vector<int>& nums, int m) {
        int low = 0, high = 0;
        for (int n: nums) {
            low = max(low, n);
            high += n;
        }

        while (low < high) {
            cout << low << " " << high << endl;
            int mid = low + (high - low) / 2;
            if (splittable(nums, m, mid)) {
                // bound can be lower than mid
                high = mid;
            } else {
                // bound must be higher than mid
                low = mid + 1;
            }
        }
        return low;
    }

private:

    bool splittable(vector<int>& nums, int parts, int upperBound) {
        int count = 1;
        int sum = 0;
        for (int n: nums) {
            if (sum + n > upperBound) {
                count++;
                sum = n;
            } else {
                sum += n;
            }
            if (count > parts) return false;
        }
        return true;
    }

};

int main() {

    vector<pair<vector<int>, int>> testCases = {
           {{7,2,5,10,8}, 2},
            {{1, 2147483646}, 1}
    };

    Solution solution;
    for (auto& p: testCases) {
        cout << solution.splitArray(p.first, p.second) << endl;
    }

    return 0;
}