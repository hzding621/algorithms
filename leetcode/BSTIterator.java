import java.util.*;

class TreeNode {
	int val;
	TreeNode left;
	TreeNode right;
	TreeNode(int x) { val = x; }
}

public class BSTIterator {
	
	private Stack<TreeNode> stack = new Stack<TreeNode>();

	public BSTIterator(TreeNode root) {
		while (root != null) {
			stack.push(root);
			root = root.left;
		}
	}

	/** @return whether we have a next smallest number */
	public boolean hasNext() {
		return !stack.empty();
	}

	/** @return the next smallest number */
	public int next() {
		TreeNode n = stack.pop();
		int ret = n.val;
		if (n.right != null) {
			n = n.right;
			while (n!= null) {
				stack.push(n);
				n = n.left;
			}
		}
		return ret;
	}
}