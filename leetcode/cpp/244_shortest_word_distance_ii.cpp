#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class WordDistance {
public:
    WordDistance(vector<string>& words) {
        for (int i = 0; i < words.size(); i++) {
            wordPosIndices[words[i]].push_back(i);
        }
    }

    int shortest(string word1, string word2) {
        auto& indices1 = wordPosIndices[word1];
        auto& indices2 = wordPosIndices[word2];
        auto merged = merge(indices1, indices2);
        int index1 = -1, index2 = -1, minDist = INT_MAX;
        for (auto& i: merged) {
            i.second? index2 = i.first : index1 = i.first;
            if (index1 >= 0 && index2 >= 0) {
                minDist = min(minDist, abs(index1 - index2));
            }
        }
        return minDist;
    }
private:
    unordered_map<string,vector<int>> wordPosIndices;

    vector<pair<int,bool>> merge(vector<int>& a, vector<int>& b) {
        vector<pair<int,bool>> result;
        int i = 0, j = 0;
        while (i < a.size() && j < b.size()) {
            if (a[i] <= b[j]) {
                result.push_back(make_pair(a[i], 0));
                i++;
            } else {
                result.push_back(make_pair(b[j], 1));
                j++;
            }
        }
        while (i < a.size()) {
            result.push_back(make_pair(a[i], 0));
            i++;
        }
        while (j < b.size()) {
            result.push_back(make_pair(b[j], 1));
            j++;
        }
        return result;
    }
};


// Your WordDistance object will be instantiated and called as such:
// WordDistance wordDistance(words);
// wordDistance.shortest("word1", "word2");
// wordDistance.shortest("anotherWord1", "anotherWord2");

int main() {

    vector<string> words = {"a", "b"};
    vector<vector<string>> cases = {
            {"a", "b"},
            {"b", "a"}
    };
    WordDistance wordDistance(words);
    for (auto& vs: cases) {
        cout << wordDistance.shortest(vs[0], vs[1]) << endl;
    }

    return 0;
}