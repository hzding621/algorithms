#include <iostream>
#include <vector>
#include <set>

using namespace std;

class Solution {
public:
    vector<string> readBinaryWatch(int num) {
        vector<string> result;
        for (int i = max(0, num-6); i <= min(num, 4); i++) {
            auto hours = findNumberWithNBitsAndKOnes(4, i);
            auto minutes = findNumberWithNBitsAndKOnes(6, num - i);
            for (int h: hours) {
                if (h > 11) continue;
                for (int m: minutes) {
                    if (m > 59) continue;
                    string hh = to_string(h);
                    string mm = to_string(m);
                    if (mm.length() == 1) mm = "0" + mm;
                    result.push_back(hh + ":" + mm);
                }
            }
        }
        return result;
    }
private:

    set<int> findNumberWithNBitsAndKOnes(int n, int k) {
        set<int> results;
        backtracking(results, n, 0, k, 0);
        return results;
    }

    void backtracking(set<int>& results,
                      int len,
                      int accumulator,
                      int bitsLeft,
                      int i) {
        if (bitsLeft == 0) {
            results.insert(accumulator);
            return;
        }
        if (i == len) {
            return;
        }
        backtracking(results, len, accumulator | (1 << i), bitsLeft - 1, i + 1);
        backtracking(results, len, accumulator, bitsLeft, i + 1);
    }
};
int main() {

    Solution solution;
    auto vs = solution.readBinaryWatch(2);

    for (auto& s: vs) {
        cout << s << endl;
    }

    return 0;
}