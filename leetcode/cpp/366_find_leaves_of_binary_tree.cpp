#include <iostream>
#include <vector>
#include <unordered_map>
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
    vector<vector<int>> findLeaves(TreeNode* root) {
        vector<vector<int>> result;
        postorder(result, root);
        return result;
    }
private:

    int postorder(vector<vector<int>>& result, TreeNode* root) {
        if (root == NULL) return -1;
        int leftHeight = postorder(result, root->left);
        int rightHeight = postorder(result, root->right);
        int currentHeight = 1 + max(leftHeight, rightHeight);
        while (currentHeight >= result.size()) {
            result.emplace_back();
        }
        result[currentHeight].push_back(root->val);
        return currentHeight;
    }
};

int main() {

    vector<int> preorder = {0,1,2,4,5,3,7};
    vector<int> inorder = {4,2,5,1,3,0,7};
    TreeNode* tree = TreeBuilder().buildTree(preorder, inorder);

    auto vvi = Solution().findLeaves(tree);
    for (auto& vi: vvi) {
        for (int i: vi) {
            cout << i << " ";
        }
        cout << endl;
    }

    return 0;
}