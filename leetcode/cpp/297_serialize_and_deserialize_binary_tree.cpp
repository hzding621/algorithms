#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <queue>

using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        stringstream ss;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
        	TreeNode* subRoot = q.front();
        	q.pop();
        	ss << nodeToString(subRoot) << ",";
        	if (subRoot) {
        		q.push(subRoot->left);
        		q.push(subRoot->right);
        	}
        }
        string output = ss.str();
        output.pop_back();
        return output;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
    	if (data.empty())
    		return NULL;
        istringstream iss(data);
        string token;
        getline(iss, token, ',');
        TreeNode* root = createNodeFromString(token);

        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
        	TreeNode* subRoot = q.front();
        	q.pop();
        	string token;
        	if (!getline(iss, token, ',')) {
        		break;
        	}
        	subRoot->left = createNodeFromString(token);
        	getline(iss, token, ',');
        	subRoot->right = createNodeFromString(token);
        	if (subRoot->left) {
        		q.push(subRoot->left);
        	}
        	if (subRoot->right) {
        		q.push(subRoot->right);
        	}
        }
        return root;
    }

private:

	TreeNode* createNodeFromString(const string& s) {
		if (s == "null") {
			return NULL;
		} else {
			int value = stoi(s);
			return new TreeNode(value);
		}
	}

	string nodeToString(const TreeNode* node) {
		if (node) {
			return to_string(node->val);
		} else {
			return "null";
		}
	}
};

int main() {
	Codec sol;
	TreeNode* root = sol.deserialize("1,2,3,null,null,4,5");
	string output = sol.serialize(root);
	cout << output << endl;
}