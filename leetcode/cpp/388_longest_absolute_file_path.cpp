#include <iostream>
#include <string>
#include <sstream>
#include <stack>
#include <algorithm>

using namespace std;

class Solution {
public:
    int lengthLongestPath(string input) {
        istringstream iss(input);
        string line;
        size_t statistics = 0;
        int currentDepth = 0;
        int currentPathLength = 0;
        int lastLineLength = 0;
        stack<int> dirLengths;
        while (getline(iss, line)) {
            int depth = getNumberOfLeadingTabs(line);
            line = line.substr(depth);
            if (depth > currentDepth) {
                currentPathLength += (lastLineLength + 1);
                currentDepth++;
                dirLengths.push(lastLineLength);
            } else if (depth < currentDepth) {
                while (currentDepth > depth) {
                    int dirToPop = dirLengths.top();
                    dirLengths.pop();
                    currentPathLength -= (dirToPop + 1);
                    currentDepth--;
                }
            }
            if (isFile(line)) {
                statistics = max(statistics, currentPathLength + line.length());
            }
            lastLineLength = line.length();
        }
        return statistics;
    }
private:
    int getNumberOfLeadingTabs(const string& s) {
        size_t i = 0;
        for (; i < s.length(); i++) {
            if (s[i] != '\t') return i;
        }
        return i;
    }

    bool isFile(const string& s) {
        for (size_t i = 0; i < s.length(); i++) {
            if (s[i] == '.') {
                return true;
            }
        }
        return false;
    }
};


int main() {

    string input = "a\n\taa\n\t\taaa\n\t\t\tfile1.txt\naaaaaaaaaaaaaaaaaaaaa\n\tsth.png";
    Solution sol;
    cout << sol.lengthLongestPath(input) << endl;

    return 0;
}