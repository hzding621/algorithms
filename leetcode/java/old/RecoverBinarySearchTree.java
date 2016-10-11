import java.util.*;

public class RecoverBinarySearchTree {

	public static void recoverTree(TreeNode root) {

		// The code is copied from the following link
		// here is used moriss in-order traversal without stack
		// http://fisherlei.blogspot.com/2012/12/leetcode-recover-binary-search-tree.html
		
		TreeNode f1 = null, f2 = null;
		TreeNode current = root, pred = null, parent = null;
		
		while (current != null) {

			if (current.left == null) {
				if (parent != null && parent.val > current.val) {
					if (f1 == null) 
						f1 = parent;
					f2 = current;
				}
				parent = current;
				current = current.right;
			} else {

				pred = current.left;
				while (pred.right != null && pred.right != current)
					pred = pred.right;

				if (pred.right == null) {
					pred.right = current;
					current = current.left;
				} else {
					pred.right = null;
					if (parent.val > current.val) {
						if (f1 == null)
							f1 = parent;
						f2 = current;
					}
					parent = current;
					current = current.right;
				}
			}
		}

		if (f1 != null && f2 != null) {
			int temp = f1.val;
			f1.val = f2.val;
			f2.val = temp;
		}

	}

	public static void main(String[] args) {
		TreeNode n = TreeNode.buildTreePreIn(new int[] {4,2,1,3,6,5,7}, new int[] {1,2,3,4,5,6,7});
		n.print();
		n.left.left.val = 2;
		n.left.val = 1;
		recoverTree(n);
		n.print();
	}
}