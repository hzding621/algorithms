#include <iostream>
#include <string>
#include <unordered_map>
#include <queue>
#include <cassert>

using namespace std;

class Solution {
public:
    string rearrangeString(string str, int k) {
        if (str.empty()) {
            return "";
        }
        unordered_map<char, int> charCounts;
        priority_queue<pair<int, char>> availableChars; // sorted by counts descending
        queue<pair<char, int>> earliestPosition; 

        for (char c: str) {
            charCounts[c]++;
        }
        for (auto& e: charCounts) {
            availableChars.push(make_pair(e.second, e.first));
        }

        string s;
        while (!availableChars.empty()) {
            
            char c = availableChars.top().second;
            availableChars.pop();
            charCounts[c]--;
            if (charCounts[c] > 0) {
                earliestPosition.push(make_pair(c, s.size()+k));
            }
            s.push_back(c);

            while (!earliestPosition.empty() && earliestPosition.front().second <= s.size()) {
                char c = earliestPosition.front().first;
                earliestPosition.pop();
                availableChars.push(make_pair(charCounts[c], c));
            }
        }

        if (s.length() < str.length()) {
            return "";
        }

        return s;
    }
};

int main() {

    vector<pair<string, int>> vs = {
        {"asjkhfajncsahasf", 4}
    };

    Solution sol;
    for (auto& e: vs) {
        cout << sol.rearrangeString(e.first, e.second) << endl;
    }

    return 0;
}