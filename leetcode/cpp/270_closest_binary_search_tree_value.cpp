#include <iostream>
#include <vector>
#include <unordered_map>
#include <climits>
#include <algorithm>

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
    int closestValue(TreeNode* root, double target) {
        int a = root->val;
        auto child = target < a ? root->left : root->right;
        if (!child) return a;
        int b = closestValue(child, target);
        return abs(a - target) < abs(b - target) ? a : b;
    }
};

int main() {

    vector<int> preorder = {0};
    vector<int> inorder = {0};
    TreeNode* tree = TreeBuilder().buildTree(preorder, inorder);
    cout << Solution().closestValue(tree, 2147483648.0) << endl;

    return 0;
}
