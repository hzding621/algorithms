#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int superPow(int a, vector<int>& b) {
        int value = 1;
        for (int i: b) {
            value = singlePow(value, 10);
            value = (value * singlePow(a, i)) % modulo;
        }
        return value;
    }
private:
    int singlePow(int a, int p) {
        if (p == 0) return 1;
        if (p == 1) return a % modulo;
        else return ((a % modulo) * singlePow(a, p-1)) % modulo;
    }
private:
    int modulo = 1337;
};

int main() {

    int a = 2;
    vector<int> b = {1, 0};
    Solution solution;
    cout << solution.superPow(a, b) << endl;
}