import java.util.*;

public class CountCompleteTreeNode {

	public static int countNodes(TreeNode root) {
		if (root == null)
			return 0;
		else if (root.left == null && root.right == null)
			return 1;
		else if (root.right == null)
			return 2;
		TreeNode n = root;
		int left = 1, right = 1;
		while (n.left != null) {
			n = n.left;
			left++;
		}
		n = root;
		while (n.right != null) {
			n = n.right;
			right++;
		}
		if (left == right) {
			return (1 << left) - 1;
		}
		else {
			left--;
			right--;
			int leftRight = 1, rightLeft = 1;
			n = root.left;
			while (n.right != null) {
				n = n.right;
				leftRight++;
			}
			n = root.right;
			while (n.left != null) {
				n = n.left;
				rightLeft++;
			}

			int leftTotal = left == leftRight ? ((1<<left)-1) : countNodes(root.left);
			int rightTotal = right == rightLeft ? ((1<<right)-1) : countNodes(root.right);
			return leftTotal + rightTotal + 1;
		}
	}

	public static void main(String[] args) {
		TreeNode n = TreeNode.buildTreePreIn(
				new int[]{1,2,4,8,9,5,10,11,3,6,12,7},
				new int[]{8,4,9,2,10,5,11,1,12,6,3,7}
			);
		n.print();
		System.out.println(countNodes(n));
	}
}
