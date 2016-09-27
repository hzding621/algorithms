#include <iostream>
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    int sumOfLeftLeaves(TreeNode* root) {
        int sum = 0;
        search(sum, root, false);
        return sum;
    }
private:
    void search(int& sum, TreeNode* sub, bool left) {
        if (sub == nullptr) return;
        if (sub->left == nullptr && sub->right == nullptr && left) sum += sub->val;
        search(sum, sub->left, true);
        search(sum, sub->right, false);
    }
};
int main() {
}