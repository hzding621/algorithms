#ifndef _tree_node_
#define _tree_node_

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	class TreeNodePrinter {
	public:

		static void printNode(TreeNode* root) {
			int ml = maxLevel(root);
			std::vector<TreeNode*> l;
			l.push_back(root);
			printNodeInternal(l, 1, ml);
		}

	private:
		static void printNodeInternal(std::vector<TreeNode*>& nodes, int level, int maxLevel) {
			if (nodes.size() == 0 || isAllElementsNull(nodes))
				return;

			int floor = maxLevel - level;
			int endgeLines = std::pow(2, std::max(floor - 1, 0));
			int firstSpaces = std::pow(2, floor) - 1;
			int betweenSpaces = std::pow(2, floor + 1) - 1;

			printWhitespaces(firstSpaces);

			std::vector<TreeNode*> newNodes;
			for (auto node : nodes) {
				if (node != NULL) {
					std::cout << node->val;
					newNodes.push_back(node->left);
					newNodes.push_back(node->right);
				} else {
					newNodes.push_back(NULL);
					newNodes.push_back(NULL);
					std::cout << " ";
				}

				printWhitespaces(betweenSpaces);
			}
			std::cout << std::endl;

			for (int i = 1; i <= endgeLines; i++) {
				for (int j = 0; j < nodes.size(); j++) {
					printWhitespaces(firstSpaces - i);
					if (nodes[j] == NULL) {
						printWhitespaces(endgeLines + endgeLines + i + 1);
						continue;
					}

					if (nodes[j]->left != NULL)
						std::cout << "/";
					else
						printWhitespaces(1);

					printWhitespaces(i + i - 1);

					if (nodes[j]->right != NULL)
						std::cout << "\\";
					else
						printWhitespaces(1);

					printWhitespaces(endgeLines + endgeLines - i);
				}

				std::cout << std::endl;
			}

			printNodeInternal(newNodes, level + 1, maxLevel);
		}

		static void printWhitespaces(int count) {
			for (int i = 0; i < count; i++)
				std::cout << " ";
		}

		static int maxLevel(TreeNode* node) {
			if (node == NULL)
				return 0;

			return std::max(maxLevel(node->left), maxLevel(node->right)) + 1;
		}

		static bool isAllElementsNull(std::vector<TreeNode*>& list) {
			for (auto& t: list) {
				if (t != NULL)
					return false;
			}
			return true;
		}

	};
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
	static void clean(TreeNode* n) {
		if (n->left) clean(n->left);
		if (n->right) clean(n->right);
		delete n;
	}
	void print() {
		TreeNodePrinter::printNode(this);
	}
};

#endif