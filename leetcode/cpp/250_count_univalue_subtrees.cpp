#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    int countUnivalSubtrees(TreeNode* root) {
        if (root == NULL) return 0;
        return postOrder(root).first;
    }
private:
    pair<int,pair<bool, int>> postOrder(TreeNode* root) {
        // only traverse non-null subtrees
        bool rootIsUnivalue = true;
        int countUniValue = 0;
        if (root->left) {
            auto leftResult = postOrder(root->left);
            if (!leftResult.second.first || leftResult.second.second != root->val) {
                rootIsUnivalue = false;
            }
            countUniValue += leftResult.first;
        }
        if (root->right) {
            auto rightResult = postOrder(root->right);
            if (!rightResult.second.first || rightResult.second.second != root->val) {
                rootIsUnivalue = false;
            }
            countUniValue += rightResult.first;
        }
        if (rootIsUnivalue) {
            countUniValue += 1;
        }
        return make_pair(countUniValue, make_pair(rootIsUnivalue, root->val));
    }
};

int main() {

    TreeNode* tree = new TreeNode(1);
    tree->right = new TreeNode(2);


    Solution solution;
    cout << solution.countUnivalSubtrees(tree) << endl;

    return 0;
}