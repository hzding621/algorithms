#include <iostream>
#include <vector>
#include <stack>

using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

template <class T>
class TreeVisitor {
public:
	void inorderTraversal(TreeNode* root, T& visitor) {
		stack<TreeNode*> _stack;
        while (root) {
            _stack.push(root);
            root = root->left;
        }
        while (!_stack.empty()) {
            TreeNode* n = _stack.top();
            _stack.pop();
            TreeNode* next = n->right;
            while (next) {
                _stack.push(next);
                next = next->left;
            }
            visitor.visit(n);
        }
	}
};

class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> result;
        Logger v;
        TreeVisitor<Logger> visitor;
        visitor.inorderTraversal(root, v);
        return v.get();
    }
private:
	class Logger {
		public: 
			void visit(TreeNode* n) {
				_result.push_back(n->val);
			}
			vector<int> get() {
				return _result;
			}
		private:
			vector<int> _result;
	};
};

int main() {


}
