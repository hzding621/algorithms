#include <algorithm>
#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
    bool verifyPreorder(vector<int>& preorder) {
        stack<int> ancestors;
        int lowerBound = INT_MIN;
        for (int v: preorder) {
            if (v < lowerBound) return false;
            while (!ancestors.empty() && v > ancestors.top()) {
                lowerBound = ancestors.top();
                ancestors.pop();
            }
            ancestors.push(v);
        }
        return true;
    }
private:

};

int main() {



    Solution solution;
    vector<int> v = {2,3,1};

    cout << solution.verifyPreorder(v) << endl;

    return 0;
}