#include <iostream>
#include <utility>
#include "../../helpers/tree_node.cpp"

using namespace std;

class Solution {
public:
    TreeNode* upsideDownBinaryTree(TreeNode* root) {
    	if (!root) return root;
        auto r = upsideDownBinaryTreeHelper(root);
        return r.first;
    }

    pair<TreeNode*, TreeNode*> upsideDownBinaryTreeHelper(TreeNode* root) {
    	if (root->left) {
    		auto left = upsideDownBinaryTreeHelper(root->left);
    		left.second->left = root->right;
    		left.second->right = root;
    		root->left = root->right = NULL;
    		return make_pair(left.first, left.second->right);
    	} else {
    		return make_pair(root, root);
    	}
    }

};

int main() {

	TreeNode* r = new TreeNode(1);
	r->left = new TreeNode(2);
	r->right = new TreeNode(3);
	r->left->left = new TreeNode(4);
	r->left->right = new TreeNode(5);
	r->print();
	Solution sol;
	TreeNode* nr = sol.upsideDownBinaryTree(r);
	nr->print();
}