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

class Solution {
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

int main() {

    vector<int> preorder = {1,2,4,5,3,6,7};
    vector<int> inorder = {4,2,5,1,6,3,7};
    TreeNode* tree = Solution().buildTree(preorder, inorder);

    return 0;
}