#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

class Solution {
public:
    int minTotalDistance(vector<vector<int>>& grid) {
        vector<int> xcoords;
        vector<int> ycoords;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j]) {
                    xcoords.push_back(i);
                    ycoords.push_back(j);
                }
            }
        }
        sort(xcoords.begin(), xcoords.end());
        sort(ycoords.begin(), ycoords.end());
        int xLen = xcoords.size(), yLen = ycoords.size();
        int x = xLen % 2 ? xcoords[xLen/2] : (xcoords[xLen/2] + xcoords[xLen/2-1]) / 2;
        int y = yLen % 2 ? ycoords[yLen/2] : (ycoords[yLen/2] + ycoords[yLen/2-1]) / 2;
        int dist = 0;
        for (int i: xcoords) {
            dist += abs(i - x);
        }
        for (int j: ycoords) {
            dist += abs(j - y);
        }
        return dist;
    }
};

int main() {

    vector<vector<int>> vv = {
        {1,0,0,0,1},
        {0,0,0,0,0},
        {0,0,1,0,0}
    };
    cout << Solution().minTotalDistance(vv) << endl;

    return 0;
}