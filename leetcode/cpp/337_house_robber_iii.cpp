#include <iostream>
#include <utility>
#include <algorithm>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    int rob(TreeNode* root) {
        auto p = robRecursive(root);
        return max(p.first, p.second);
    }
private:
    pair<int,int> robRecursive(TreeNode* root) {
        if (root == NULL) {
            return make_pair(0, 0);
        }
        auto p1 = robRecursive(root->left);
        auto p2 = robRecursive(root->right);

        int doNotRobHere = max(p1.first, p1.second) + max(p2.first, p2.second);
        int robHere = root->val + p1.first + p2.first;
        return make_pair(doNotRobHere, robHere);
    }
};

int main() {

    return 0;
}