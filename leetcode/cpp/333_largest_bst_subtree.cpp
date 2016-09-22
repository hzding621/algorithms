#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <map>
#include <set>
#include <climits>
#include <algorithm>
#include <utility>
#include <list>
#include <sstream>
#include <string>
#include <chrono>

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
    int largestBSTSubtree(TreeNode* root) {
        if (root == nullptr) return 0;
        auto result = postOrderTraversal(root);
        return get<0>(result);
    }

private:

    // return four things (i, b, l, r)
    // i: largest BST below root
    // b: whether root itself is BST
    // l: leftBound of root if root is BST
    // r: rightBound of root if root is BST
    tuple<int,bool,int,int> postOrderTraversal(TreeNode *root) {
        bool isBST = true;
        int largest = 1;
        int size = 1, leftBound = root->val, rightBound = root->val;
        if (root->left) {
            auto left = postOrderTraversal(root->left);
            if (!get<1>(left) || get<3>(left) > root->val) {
                isBST = false;
            } else {
                size += get<0>(left);
                leftBound = get<2>(left);
            }
            largest = max(largest, get<0>(left));
        }
        if (root->right) {
            auto right = postOrderTraversal(root->right);
            if (!get<1>(right) || get<2>(right) < root->val) {
                isBST = false;
            } else {
                size += get<0>(right);
                rightBound = get<3>(right);
            }
            largest = max(largest, get<0>(right));
        }
        if (!isBST) {
            // last two numbers are unused
            return make_tuple(largest, false, 0, 0);
        } else {
            return make_tuple(size, true, leftBound, rightBound);
        }
    }
};

int main() {

    vector<int> preorder = {10, 5, 1, 8, 15, 7};
    vector<int> inorder = {1, 5, 8, 10, 15, 7};
    TreeNode* tree = TreeBuilder().buildTree(preorder, inorder);

    Solution solution;
    cout << solution.largestBSTSubtree(tree) << endl;

    return 0;
}