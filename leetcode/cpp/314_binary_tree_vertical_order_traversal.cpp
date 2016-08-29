#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <unordered_map>

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
    vector<vector<int>> verticalOrder(TreeNode* root) {
        if (root == NULL) return {};

        TreeNode* cursor = root;
        int leftOffset = 0;
        vector<vector<int>> left;
        vector<vector<int>> right;
        bfs(left, right, root);
        reverse(left.begin(), left.end());
        for (auto& vi: right) {
            left.push_back(vi);
        }
        return left;
    }

private:

    void bfs(vector<vector<int>>& left, vector<vector<int>>& right, TreeNode* root) {
        queue<pair<TreeNode*,int>> q;
        q.push(make_pair(root, 0));
        while (!q.empty()) {
            TreeNode* n; int order; 
            tie(n, order) = q.front(); q.pop();
            if (n == NULL) continue;
            if (order >= 0) {
                while (order >= right.size()) {
                    right.emplace_back();
                }
                right[order].push_back(n->val);
            } else {
                while (-order-1 >= left.size()) {
                    left.emplace_back();
                }
                left[-order-1].push_back(n->val);
            }
            q.push(make_pair(n->left, order-1));
            q.push(make_pair(n->right, order+1));
        }
    }
};

int main() {

    vector<int> preorder = {1,4,3,2,5,6};
    vector<int> inorder = {1,2,3,4,5,6};
    TreeNode* tree = TreeBuilder().buildTree(preorder, inorder);
    vector<vector<int>> vvi = Solution().verticalOrder(tree);
    for (auto& vi: vvi) {
        for (int i: vi) {
            cout << i << " ";
        }
        cout << endl;
    }

    return 0;
}