#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maxProduct(vector<string>& words) {
        vector<int> bitMasks;
        for (const auto& s: words) {
            bitMasks.push_back(generateBitMask(s));
        }
        int maxProduct = 0;
        for (int i = 0; i < words.size(); i++) {
            for (int j = 0; j < words.size(); j++) {
                if (i == j) continue;
                if (!(bitMasks[i] & bitMasks[j])) {
                    maxProduct = max((int) (words[i].length() * words[j].length()), maxProduct);
                }
            }
        }
        return maxProduct;
    }

private:
    int generateBitMask(const string& s) {
        int mask = 0;
        for (char c: s) {
            mask |= (1 << (c- 'a'));
        }
        return mask;
    }
};

int main() {

    vector<string> vs = {"a", "aa", "aaa", "aaaa"};
    Solution sol;
    cout << sol.maxProduct(vs) << endl;

    return 0;
}
