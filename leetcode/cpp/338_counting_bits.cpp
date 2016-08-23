#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> v = {0};
        int currentSize = 1;
        while (currentSize <= num) {
            for (int i = 0; i < currentSize; i++) {
                v.push_back(v[i] + 1);
            }
            currentSize = v.size();
        }
        while (v.size() > num + 1) {
            v.pop_back();
        }
        return v;
    }
};

int main() {

    Solution sol;
    auto vi = sol.countBits(10);
    for (int i: vi) {
        cout << i <<  " ";
    }
    cout << endl;

    return 0;
}