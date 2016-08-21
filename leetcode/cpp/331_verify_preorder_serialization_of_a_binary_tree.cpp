#include <iostream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

class Solution {
public:
    bool isValidSerialization(string preorder) {
        if (preorder == "#")
            return true;
        vector<int> nodes;
        bool finished = false;
        istringstream iss(preorder);
        string token;
        while (getline(iss, token, ',')) {
            bool isNumber = token != "#";
            if (isNumber) {
                if (finished) {
                    return false;
                } else {
                    nodes.push_back(0);
                }
            } else {
                if (nodes.empty()) {
                    return false;
                }
                while (!nodes.empty() && nodes.back() == 1) {
                    nodes.pop_back();
                }
                if (!nodes.empty()) {
                    nodes.back() = nodes.back() + 1;
                } else {
                    finished = true;
                }
            }
        }        
        return nodes.empty();
    }
};

int main() {

    string tree = "9,3,4,#,#,1,#,#,#,2,#,6,#,#";
    Solution sol;
    cout << sol.isValidSerialization(tree) << endl;

    return 0;
}