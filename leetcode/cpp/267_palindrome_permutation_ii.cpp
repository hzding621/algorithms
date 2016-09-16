#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<string> generatePalindromes(string s) {
        int len = s.length();
        unordered_map<char,int> charCounts;
        for (char c: s) {
            charCounts[c]++;
        }

        char singletonChar = 0;
        for (auto& kv: charCounts) {
            if (kv.second % 2) {
                if (len % 2 && !singletonChar) {
                    singletonChar = kv.first;
                } else {
                    return {};
                }
            }
        }
        if (len % 2)
            charCounts[singletonChar]--;
        vector<string> answer;
        string partial;
        findPalindromes(answer, charCounts, len - (len % 2), partial);

        for (auto& half: answer) {
            int l = half.length();
            if (len % 2) {
                half.push_back(singletonChar);
            }
            for (int i = l-1; i >= 0; i--) {
                half.push_back(half[i]);
            }
        }
        return answer;
    }
private:
    void findPalindromes(vector<string>& output, unordered_map<char,int>& charCounts, int size, string& partial) {
        if (size == 0) {
            output.push_back(partial);
            return;
        }

        for (auto& e: charCounts) {
            if (e.second == 0)
                continue;
            char c = e.first;
            partial.push_back(c);
            charCounts[c]-=2;
            findPalindromes(output, charCounts, size - 2, partial);
            partial.pop_back();
            charCounts[c]+=2;
        }
    }
};

int main() {

    Solution sol;
    vector<string> vs = sol.generatePalindromes("aaaa");
    for (auto& s: vs) {
        cout << s << endl;
    }

    return 0;
}