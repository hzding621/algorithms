#include <iostream>

using namespace std;

class Solution {
public:
    bool isPowerOfTwo(int n) {
        return n > 0 && !(n & (n-1));
    }
};

int main() {
    Solution sol;
    cout << boolalpha;
    for (int i=0; i<= 100; i++)
        cout << i << " " << sol.isPowerOfTwo(i) << endl;
}
