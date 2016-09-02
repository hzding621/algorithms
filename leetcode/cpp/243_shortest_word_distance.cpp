#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int shortestDistance(vector<string>& words, string word1, string word2) {
        int index1 = -1, index2 = -1, minDist = INT_MAX;
        for (int i = 0; i < words.size(); i++) {
            if (words[i] == word1) {
                index1 = i;
            }
            if (words[i] == word2) {
                index2 = i;
            }
            if (index1 >= 0 && index2 >= 0) {
                minDist = min(minDist, abs(index1 - index2));
            }
        }
        return minDist;
    }
};

int main() {

    vector<string> words = {"practice", "makes", "perfect", "coding", "makes"};
    vector<vector<string>> cases = {
            {"coding", "practice"},
            {"makes", "coding"}
    };

    Solution sol;
    for (auto& vs: cases) {
        cout << sol.shortestDistance(words, vs[0], vs[1]) << endl;
    }

    return 0;
}