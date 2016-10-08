#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    string minAbbreviation(string target, vector<string>& dictionary) {
        int len = (int) target.length();
        vector<bitset<21>> masks;
        for (string& s: dictionary) {
            if (s.length() != len) continue;
            bitset<21> mask;
            for (int i = 0; i < len; i++) {
                if (s[i] != target[i]) mask[i] = true;
            }
            masks.push_back(mask);
        }

        bitset<21> ors;
        for (auto& m: masks) {
            ors |= m;
        }
        bitset<21> best, partial;
        int bestLength = INT_MAX;
        dfs(masks, ors, bestLength, best, 0, partial, 0, len, false);
        return reconstructFromMask(target, best);
    }
private:
    void dfs(vector<bitset<21>> &masks, bitset<21> &ors,
             int &bestLength, bitset<21> &best,
             int curLength, bitset<21> &partial, int i, int len, bool consecutiveZeros) {

        if (curLength >= bestLength) return; // avoid repeated computation since any minimum abbr is OK
        if (i == len) {
            if (allPositive(masks, partial)) {
                if (curLength < bestLength) {
                    bestLength = curLength;
                    best = partial;
                }
            }
            return;
        }
        if (ors[i]) {
            partial[i] = true;
            dfs(masks, ors, bestLength, best, curLength + 1, partial, i + 1, len, false);
            partial[i] = false;
        }

        // pass in consecutiveZeros to compute curLength
        if (consecutiveZeros) {
            dfs(masks, ors, bestLength, best, curLength, partial, i + 1, len, true);
        } else {
            dfs(masks, ors, bestLength, best, curLength + 1, partial, i + 1, len, true);
        }
    }

    bool allPositive(vector<bitset<21>>& masks, bitset<21>& partial) {
        // check m & partial > 0 for all m in masks
        for (auto& m: masks) {
            auto and_ = m & partial;
            if (and_.none()) return false;
        }
        return true;
    }

    string reconstructFromMask(string& target, bitset<21>& mask) {
        string output;
        int i = 0;
        while (i < target.length()) {
            if (mask[i] == false) {
                int j = i;
                while (j < target.length() && mask[j] == false) {
                    j++;
                }
                output += to_string(j - i);
                i = j;
            } else {
                output.push_back(target[i++]);
            }
        }
        return output;
    }
};

int main() {
    vector<pair<string, vector<string>>> testCases = {
            {"abcde", {"abxdx", "xbcdx"}},
            {"apple", {"blade"}},
            {"apple", {"plain", "amber", "blade"}},
            {"leetcode", {"lyftcode","leetcold","litecode","lietcode","leetccod","lyftcold"}}
    };

    Solution solution;
    for (auto& p: testCases) {
        cout << solution.minAbbreviation(p.first, p.second) << endl;
    }
}