class Solution {
public:
    vector<int> closestKValues(TreeNode* root, double target, int k) {
        stack<TreeNode*> predecessors, successors;
        initializePredecessors(predecessors, root, target);
        initializeSuccessors(successors, root, target);
        if (predecessors.size() && successors.size() && predecessors.top()->val == successors.top()->val) {
            moveSuccessors(successors);
        }

        vector<int> result;
        while (k--) {
            // Input tree is guaranteed to have k neareast neighbors
            if (successors.empty() && predecessors.empty()) {
              throw invalid_argument("There are fewer than " + to_string(k) + " nodes in the tree.");
            } else if (successors.empty()) {
                result.push_back(movePredecessors(predecessors));
            } else if (predecessors.empty()) {
                result.push_back(moveSuccessors(successors));
            } else {
                int leftNeighbor = predecessors.top()->val;
                int rightNeighbor = successors.top()->val;
                if (abs(leftNeighbor - target) < abs(rightNeighbor - target)) {
                    result.push_back(movePredecessors(predecessors));
                } else {
                    result.push_back(moveSuccessors(successors));
                }
            }
        }
        return result;
    }
private:
    void initializeSuccessors(stack<TreeNode*>& s, TreeNode* root, double target) {
        while (root != NULL) {
            if (root->val == target) {
                s.push(root);
                return;
            }
            if (root->val > target) {
                s.push(root);
                root = root->left;
            } else {
                root = root->right;
            }
        }
    }

    void initializePredecessors(stack<TreeNode*>& s, TreeNode* root, double target) {
        while (root != NULL) {
            if (root->val == target) {
                s.push(root);
                return;
            }
            if (root->val < target) {
                s.push(root);
                root = root->right;
            } else {
                root = root->left;
            }
        }
    }

    int moveSuccessors(stack<TreeNode*>& s) {
        TreeNode* cursor = s.top();
        s.pop();
        int value = cursor->val;
        cursor = cursor->right;
        while (cursor) {
            s.push(cursor);
            cursor = cursor->left;
        }
        return value;
    }

    int movePredecessors(stack<TreeNode*>& s) {
        TreeNode* cursor = s.top();
        s.pop();
        int value = cursor->val;
        cursor = cursor->left;
        while (cursor) {
            s.push(cursor);
            cursor = cursor->right;
        }
        return value;
    }
};