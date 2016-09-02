#include <iostream>

using namespace std;

bool knows(int a, int b);

class Solution {
public:
    int findCelebrity(int n) {
        int i = 0, j = 1;
        while (i < n && j < n) {
            bool ij = knows(i, j);
            if (ij) {
                // j is candidate
                i = j;
            } // else i is candidate
            j += 1;
        }
        if (i >= n) return -1;
        // i is candidate
        for (int k = 0; k < n; k++) {
            if (k == i) continue;
            if (knows(i, k) || !knows(k, i)) return -1;
        }
        return i;
    }
};

int main() {

}