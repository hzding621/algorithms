/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class BSTIterator {
public:
    BSTIterator(TreeNode *root) {
        while (root) {
            _stack.push(root);
            root = root->left;
        }
    }

    /** @return whether we have a next smallest number */
    bool hasNext() {
        return !_stack.empty();
    }

    /** @return the next smallest number */
    int next() {
        TreeNode* n = _stack.top();
        int ret = n->val;
        _stack.pop();
        n = n->right;
        while (n) {
            _stack.push(n);
            n = n->left;
        }
        return ret;
    }
private:
    stack<TreeNode*> _stack;
};

/**
 * Your BSTIterator will be called like this:
 * BSTIterator i = BSTIterator(root);
 * while (i.hasNext()) cout << i.next();
 */