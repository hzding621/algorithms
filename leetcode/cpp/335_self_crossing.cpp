#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool isSelfCrossing(vector<int>& x) {
        // compact but equivalent version

        if (x.size() <= 3) {
            return false;
        }
        x.push_back(0);
        x.push_back(0);
        int a = 0, b = 0, c = 0, d = 0, e = 0, f = 0;
        for (int i: x) {
            a = b, b = c, c = d, d = e, e = f, f = i;
            if (d >= b && b > 0 && 
                    (a >= c // 4 segments crossing
                 || (a >= c-e && c >= e && f >= d-b // 6 segments crossing
                ))) {
                return true;
            }
        }
        return false;
    }

    // bool isSelfCrossing(vector<int>& x) {
    //     int n = x.size();
    //     if (n <= 3) {
    //         return false;
    //     }

    //     // check the fourth line
    //     int a = x[0], b = x[1], c = x[2], d = x[3], i = 4;
    //     while (true) {
    //         if (d >= b && a >= c)
    //             return true;
    //         if (i < n) {
    //             a = b, b = c, c = d, d = x[i++];
    //         } else {
    //             break;
    //         }
    //     }

    //     if (n <= 4) {
    //         return false;
    //     }

    //     // check the fifth line
    //     a = x[0], b = x[1], c = x[2], d = x[3], i = 5;
    //     int e = x[4];
    //     while (true) {
    //         if (d == b && e >= c-a) {
    //             return true;
    //         }
    //         if (i < n) {
    //             a = b, b = c, c = d, d = e, e = x[i++];
    //         } else {
    //             break;
    //         }
    //     }

    //     if (n <= 5) {
    //         return false;
    //     }

    //     // check the sixth line
    //     a = x[0], b = x[1], c = x[2], d = x[3], e = x[4], i = 6;
    //     int f = x[5];
    //     while (true) {
    //         if (d >= b && e >= c - a && c >= e && f >= d - b) {
    //             return true;
    //         }
    //         if (i < n) {
    //             a = b, b = c, c = d, d = e, e = f, f = x[i++];
    //         } else {
    //             break;
    //         }
    //     }

    //     return false;
    // }
};

int main() {

    vector<int> v = {1,1,1,1};
    Solution sol;
    cout << sol.isSelfCrossing(v) << endl;

    return 0;
}