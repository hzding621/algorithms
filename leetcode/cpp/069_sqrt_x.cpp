#include <iostream>
#include <vector>

using namespace std;

int mySqrt(int n) {

    long start = 0, end = n;
    while (start + 1 < end) {

        long middle = (start + end) / 2;
        long square = middle * middle;
        if (square == n) {
            return (int)middle;
        } else if (square < n) {
            start = middle;
        } else {
            end = middle;
        }
    }
    if (start == end) {
        return (int)start;
    } else {
        return (int)(end * end <= n ? end : start);
    }

}

int main() {

    vector<int> testCases = {0, 1, 4, 5, 9, 12, 16, 19, 25, 35, 36, 48};

    for (int n: testCases) {
        cout << n << ": " << mySqrt(n) << endl;
    }
}