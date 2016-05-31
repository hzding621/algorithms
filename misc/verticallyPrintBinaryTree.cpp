#include <iostream>
#include <stack>
#include <utility>
#include <vector>
#include <unordered_map>
using namespace std;
typedef struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int n) : val{n}, left{NULL}, right{NULL} {}
} TreeNode;

void traverse(unordered_map<int, vector<int>>& columns, pair<int,int>& range, int order, TreeNode* node) {
	if (node == NULL) return;
	range.first = min(range.first, order);
	range.second = max(range.second, order);
	columns[order].push_back(node->val);
	
	traverse(columns, range, order-1, node->left);
	traverse(columns, range, order+1, node->right);
}

vector<vector<int>> printBinaryTreeVertically(TreeNode* root) {
	
	unordered_map<int, vector<int>> columns;
	pair<int,int> range;
	traverse(columns, range, 0, root);
	vector<vector<int>> result;
	for (int i=range.first; i<=range.second; i++) {
		result.push_back(columns[i]);
	}
	return result;
}

int main() {

	TreeNode *n1 = new TreeNode(1);
	n1->left = new TreeNode(2);
	n1->left->right = new TreeNode(5);
	n1->left->left = new TreeNode(4);
	n1->right = new TreeNode(3);
	n1->right->left = new TreeNode(6);
	n1->right->right = new TreeNode(7);
	n1->right->left->right = new TreeNode(8);
	n1->right->right->right = new TreeNode(9);
	vector<vector<int>> vv = printBinaryTreeVertically(n1);
	for (auto& v: vv) {
		for (int i: v)
			cout << i << " ";
		cout << endl; 
	}


	return 0;
}