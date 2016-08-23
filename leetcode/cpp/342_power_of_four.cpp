#include <iostream>

using namespace std;

const int MAX_POWER_OF_FOUR = 1073741824;

class Solution {
public:
    bool isPowerOfFour(int num) {
        return num > 0 && (num & (num - 1)) == 0 && (num - 1) % 3 == 0;
    }
};

int main() {

    return 0;
}