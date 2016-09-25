#include <iostream>

using namespace std;

class Solution {
public:
    int lastRemaining(int n) {
        // stolen from here:
        // https://discuss.leetcode.com/topic/58042/c-1-line-solution-with-explanation/2
        return n == 1 ? 1 : 2 * (1 + n / 2 - lastRemaining(n / 2));
    }
};

int main() {

    return 0;
}