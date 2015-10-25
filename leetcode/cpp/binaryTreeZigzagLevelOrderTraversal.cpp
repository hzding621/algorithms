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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> result;
        vector<TreeNode*> currentLevel;
        vector<TreeNode*> nextLevel;
        if (root) currentLevel.push_back(root);
        bool isReversed = false;
        while (currentLevel.size()) {
            vector<int> v;
            if (isReversed) {
                for (auto it=currentLevel.rbegin(); it != currentLevel.rend(); it++)
                    v.push_back((*it)->val);
            } else {
                for (TreeNode* it: currentLevel)
                    v.push_back(it->val);
            }
            result.push_back(v);
            for (TreeNode* it: currentLevel) {
                if (it->left) nextLevel.push_back(it->left);
                if (it->right) nextLevel.push_back(it->right);
            }
            swap(currentLevel, nextLevel);
            nextLevel.clear();
            isReversed = !isReversed;
        }
        return result;
    }
};