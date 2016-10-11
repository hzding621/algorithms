import java.util.*;

public class BinaryTreeRightSideView {

	public static List<Integer> rightSideView(TreeNode root) {
		List<Integer> ans = new ArrayList<Integer>();
		if (root == null)
			return ans;

		List<TreeNode> nextLevel = new ArrayList<TreeNode>();
		List<TreeNode> thisLevel = new ArrayList<TreeNode>();
		thisLevel.add(root);
		while (!thisLevel.isEmpty()) {
			ans.add(thisLevel.get(0).val);
			for (TreeNode n : thisLevel) {
				if (n.right != null)
					nextLevel.add(n.right);	
				if (n.left != null)
					nextLevel.add(n.left);
			}
			thisLevel = nextLevel;
			nextLevel = new ArrayList<TreeNode>();
		}
		return ans;
	}

	public static void main(String[] args) {
		TreeNode n = TreeNode.buildTreeInPost(new int[] {4,5,2,1,3}, new int[] {5,4,2,3,1});
		List<Integer> l = rightSideView(n);
		for (int i: l) {
			System.out.print(i+" ");
		}
	}


}