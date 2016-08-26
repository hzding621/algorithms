#include <iostream>
#include <utility>
#include <unordered_map>
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class TreeBuilder {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int,int> valueToPosInInorder;
        for (int i = 0; i < inorder.size(); i++) {
            valueToPosInInorder[inorder[i]] = i;
        }
        return buildTreeRecursion(preorder, 0, preorder.size()-1, valueToPosInInorder, 0, inorder.size()-1);
    }

private:
    TreeNode* buildTreeRecursion(vector<int>& preorder, int i1, int j1, unordered_map<int,int>& valueToPosInInorder, int i2, int j2) {

        if (i1 > j1 || i2 > j2) {
            return NULL;
        }
        if (i1 == j1 && i2 == j2) {
            return new TreeNode(preorder[i1]);
        }
        int rootValue = preorder[i1];
        int rootPos = valueToPosInInorder[rootValue];
        int leftTreeSize = rootPos - i2;
        TreeNode* root = new TreeNode(rootValue);
        root->left = buildTreeRecursion(preorder, i1 + 1, i1 + leftTreeSize, valueToPosInInorder, i2, rootPos - 1);
        root->right = buildTreeRecursion(preorder, i1 + leftTreeSize + 1, j1, valueToPosInInorder, rootPos + 1, j2);
        return root;
    }
};

class Solution {
public:
    int longestConsecutive(TreeNode* root) {
        if (root == NULL) {
            return 0;
        }
        return traverse(root).first;
    }
private:

    pair<int,int> traverse(TreeNode* subroot) {
        // recursively return two values: 
        // - longest path in the entire subtree
        // - longest path starting at the subroot    
        int longestEntire = 1, longestFromRoot = 1;
        if (subroot->left) {
            auto p = traverse(subroot->left);
            int leftValue = subroot->left->val;
            if (subroot->val + 1 == leftValue) {
                longestFromRoot = max(longestFromRoot, p.second + 1);
            }
            longestEntire = max(longestEntire, p.first);
        }
        if (subroot->right) {
            auto p = traverse(subroot->right);
            int rightValue = subroot->right->val;
            if (subroot->val + 1 == rightValue) {
                longestFromRoot = max(longestFromRoot, p.second + 1);
            }
            longestEntire = max(longestEntire, p.first);
        }
        longestEntire = max(longestEntire, longestFromRoot);
        return make_pair(longestEntire, longestFromRoot);
    }
};

int main() {

    TreeBuilder treeBuilder;
    vector<int> preorder = {1,3,2,4,5};
    vector<int> inorder = {1,2,3,4,5};
    TreeNode* tree = treeBuilder.buildTree(preorder, inorder);

    Solution sol;
    cout << sol.longestConsecutive(tree) << endl;

    return 0;
}