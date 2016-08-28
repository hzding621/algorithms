#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> lexicalOrder(int n) {
        vector<int> result;
        int i = 1;
        while (result.empty() || i != 1) {
            if (i <= n) {
                result.push_back(i);
            }
            if (i * 10 <= n) {
                i *= 10;
            } else {
                i += 1;
                while (i % 10 == 0) {
                    i /= 10;
                }
            }
        }
        return result;
    }
};

int main() {

    Solution sol;
    vector<int> vi = sol.lexicalOrder(156);
    for (int i: vi) {
        cout << i << endl;
    }

    return 0;
}