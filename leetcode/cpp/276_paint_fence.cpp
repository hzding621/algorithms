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
    int numWays(int n, int k) {
        if (n == 0 || k == 0) return 0;
        if (n == 1) return k;
        int lastTwoHaveSameColor = k;
        int lastTwoHaveDifferentColor = k * (k-1);
        for (int i = 2; i < n; i++) {
            int temp = lastTwoHaveDifferentColor;
            lastTwoHaveDifferentColor = (lastTwoHaveDifferentColor + lastTwoHaveSameColor) * (k-1);
            lastTwoHaveSameColor = temp;
        }
        return lastTwoHaveDifferentColor + lastTwoHaveSameColor;
    }
};

int main() {

    return 0;
}