#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>
#include <unordered_map>

using namespace std;

class Solution {
public:
    string alienOrder(vector<string>& words) {
        unordered_map<char, int> charSetMark;
        unordered_map<char, unordered_set<char>> neighbors;
        if (!findRelations(words, charSetMark, neighbors)) {
            return "";
        }        
        // DFS version Topological Sort
        string sortedChars;
        for (auto& e: charSetMark) {
            char c = e.first;
            if (charSetMark[c] == 0) {
                if (!dfs(c, sortedChars, charSetMark, neighbors)) {
                    return "";
                }
            }
        }
        reverse(sortedChars.begin(), sortedChars.end());
        return sortedChars;
    }
private:
    bool dfs(char currentNode, 
             string& sortedChars, 
             unordered_map<char, int>& charSetMark, 
             unordered_map<char, unordered_set<char>>& neighbors) {
        if (charSetMark[currentNode] == 1) {
            // Cycle 
            return false;
        }
        if (charSetMark[currentNode] == 2) {
            return true;
        }
        charSetMark[currentNode] = 1;
        for (char c: neighbors[currentNode]) {
            if (!dfs(c, sortedChars, charSetMark, neighbors)) {
                return false;
            }
        }
        charSetMark[currentNode] = 2;
        sortedChars.push_back(currentNode);
        return true;
    }

    bool findRelations(vector<string>& words, 
                       unordered_map<char, int>& charSetMark, 
                       unordered_map<char, unordered_set<char>>& neighbors) {
        for (string& s: words) {
            for (char c: s) {
                charSetMark[c] = 0;
            }
        }
        for (int i = 1; i < words.size(); i++) {
            int j = 0;
            while (j < words[i-1].length() && j < words[i].length()) {
                if (words[i-1][j] != words[i][j]) {
                    neighbors[words[i-1][j]].insert(words[i][j]);
                    break;
                }
                j++;
            }
            if (j == words[i].length() && j < words[i-1].length()) {
                // a string is a prefix of a previous string
                return false;
            }
        }
        return true;
    }
};

int main() {

    vector<string> words = {
        "b",
        "bb",
        "bc",
        "bcc",
        "bca"
    };
    Solution sol;
    cout << sol.alienOrder(words) << endl;

    return 0;
}