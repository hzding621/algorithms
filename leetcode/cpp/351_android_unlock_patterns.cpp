#include <iostream>
#include <vector>
#include <unordered_map>
#include <cassert>

using namespace std;

class Solution {
public:
    int numberOfPatterns(int m, int n) {
        int usedDigits = 1; // 0 is used
        vector<vector<bool>> canTravel;
        for (int i = 0; i <= 9; i++) {
            canTravel.emplace_back(10);
            for (int j: neighbors[i]) {
                canTravel[i][j] = true;
            }
        }
        unordered_map<int,int> cache;
        int totalCount = 0;
        canTravel[0][1] = 1; // starting point is at the corner
        totalCount += 4 * dfs(m, n, usedDigits, 0, 0, canTravel, cache);
        canTravel[0][1] = 0, canTravel[0][2] = 1; // starting point is at middle of the edge
        totalCount += 4 * dfs(m, n, usedDigits, 0, 0, canTravel, cache);
        canTravel[0][2] = 0, canTravel[0][5] = 1; // starting point is at the center
        totalCount += dfs(m, n, usedDigits, 0, 0, canTravel, cache);
        canTravel[0][5] = 0;
        return totalCount;
    }
private:

    inline int codeOf(int currentDigit, int unused) {
        // 9 bits for unused, 4 bits for currentDigit
        // these two parameters UNIQUELY defines the state
        // other parameters are derivable from these two values
        return (unused << 4) + currentDigit;
    }

    int dfs(int m, int n,
            int usedDigits, int currentDigit,
            int currentLength, vector<vector<bool>> &canTravel,
            unordered_map<int, int> &cache) {
        if (currentLength > n) {
            return 0;
        }
        int code = codeOf(currentDigit, usedDigits);
        if (cache.count(code)) return cache[code];
        int count = currentLength >= m;
        for (int nextDigit = 1; nextDigit <= 9; nextDigit++) {
            if (!(usedDigits & 1 << nextDigit) && canTravel[currentDigit][nextDigit]) {
                adjustTravelRules(nextDigit, canTravel, true);
                usedDigits ^= 1 << nextDigit;
                count += dfs(m, n, usedDigits, nextDigit, currentLength + 1, canTravel, cache);
                adjustTravelRules(nextDigit, canTravel, false);
                usedDigits ^= 1 << nextDigit;
            }
        }
        if (currentDigit > 0) // do not cache the special starting digit
            cache[code] = count;
        return count;
    }

    const vector<vector<int>> neighbors = {
            {}, // 0 reserved by special starting point
            {2,4,5,6,8},
            {1,3,4,5,6,7,9},
            {2,4,5,6,8},
            {1,2,3,5,7,8,9},
            {1,2,3,4,6,7,8,9},
            {1,2,3,5,7,8,9},
            {2,4,5,6,8},
            {1,3,4,5,6,7,9},
            {2,4,5,6,8}
    };

    void adjustTravelRules(int digit, vector<vector<bool>> &canTravel, bool activate) {
        static vector<vector<pair<int,int>>> rules = {
                {},
                {},
                {{1,3}}, // 1->2->3
                {},
                {{1,7}}, // 1->4->7
                {{2,8},{4,6},{1,9},{3,7}}, // 2->5->8, ...
                {{3,9}},
                {},
                {{7,9}},
                {}
        };

        for (auto& p: rules[digit]) {
            canTravel[p.first][p.second] = canTravel[p.second][p.first] = activate;
        }
    }
};

int main() {

    Solution sol;
    for (int i = 0; i < 9; i++) {
        cout << '{';
        for (int j = 0; j < 9; j++) {
            cout << sol.numberOfPatterns(i+1, j+1);;
            if (j < 8) cout << ',';
        }
        cout << "}," << endl;
    }
    return 0;
}