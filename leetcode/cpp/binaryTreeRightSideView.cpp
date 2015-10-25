/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> result;
        vector<TreeNode*> currentLevel;
        vector<TreeNode*> nextLevel;
        if (root) currentLevel.push_back(root);
        while (currentLevel.size()) {
            result.push_back(currentLevel[0]->val);
            for (TreeNode* t: currentLevel) {
                if (t->right) nextLevel.push_back(t->right);
                if (t->left) nextLevel.push_back(t->left);
            }
            swap(currentLevel, nextLevel);
            nextLevel.clear();
        }
        return result;
    }
};