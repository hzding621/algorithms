#include <iostream>

using namespace std;

const int ANSWER = 1702766719;

int guess(int num) {
    return ANSWER < num ? -1 : ANSWER > num ? 1 : 0;
}

//2126753390
//1702766719

class Solution {
public:
    int guessNumber(int n) {
        int low = 1, high = n;
        while (low != high) {
            int middle = low + (high - low) / 2;
            int result = guess(middle);
            if (result == 0) {
                return middle;
            } else if (result > 0) {
                low = middle + 1;
            } else {
                high = middle - 1;
            }
        }
        return low;
    }
};

int main() {

    Solution sol;
    cout << sol.guessNumber(2126753390) << endl;

    return 0;
}