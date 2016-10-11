/* https://oj.leetcode.com/problems/balanced-binary-tree/ */

public class Test4_1 {
	public static int checkHeight(TreeNode node) {
		if (node == null)
			return 0;
		int leftHeight = checkHeight(node.left);
		int rightHeight = checkHeight(node.right);
		if (leftHeight == -1 || rightHeight == -1)
			return -1;

		if (Math.abs(leftHeight-rightHeight)>1)
			return -1;
		return Math.max(leftHeight, rightHeight)+1;

	}

	public static boolean isBalanced(TreeNode node) {
		return checkHeight(node) != -1;
	}
}