import java.util.*;

public class BinaryTreeZigZagLevelOrderTraversal {

	public List<List<Integer>> zigzagLevelOrder(TreeNode root) {
        
		List<List<Integer>> ans = new ArrayList<List<Integer>>();
		if (root == null)
			return ans;

		boolean reverse = false;
		List<TreeNode> nextLevel = new ArrayList<TreeNode>();
		List<TreeNode> thisLevel = new ArrayList<TreeNode>();
		thisLevel.add(root);
		while (!thisLevel.isEmpty()) {
			
			List<Integer> l = new ArrayList<Integer>();
			for (TreeNode n : thisLevel) {
				l.add(n.val);
				if (n.left != null)
					nextLevel.add(n.left);
				if (n.right != null)
					nextLevel.add(n.right);
			}
			if (reverse)
				Collections.reverse(l);
			ans.add(l);
			thisLevel = nextLevel;
			nextLevel = new ArrayList<TreeNode>();
			reverse = !reverse;
		}
		return ans;
	}

	public static void main(String[] args) {
		
	}
}