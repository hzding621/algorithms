// https://leetcode.com/problems/path-sum-ii/

import java.util.*;

public class PathSum {
	public static List<List<Integer>> pathSum(TreeNode root, int sum) {
		ArrayList<Integer> path = new ArrayList<Integer>();
		List<List<Integer>> result = new ArrayList<List<Integer>>();
		traverse(root, sum, path, result);
		return result;
	}

	static void traverse(TreeNode node, int sum, ArrayList<Integer> path, List<List<Integer>> result) {
		if (node == null)
			return;
		path.add(node.val);
		if (node.left == null && node.right == null) {
			if (checkSum(path, sum))
				result.add(new ArrayList<Integer>(path));
		}
		traverse(node.left, sum, path, result);
		traverse(node.right, sum, path, result);
		path.remove(path.size()-1);
	}
	
	static boolean checkSum(List<Integer> l, int sum) {
		for (int i: l)
			sum -= i;
		return sum == 0;
	}

	public static void main(String[] args) {
		TreeNode n = new TreeNode("5 4 11 7 * * 2 * * * 8 13 * * 4 5 * * 1 * *");
		n.print();
		List<List<Integer>> ll = pathSum(n, 22);
		for (List<Integer> l: ll) {
			for (int i: l)
				System.out.print(i + " ");
			System.out.println();
		}
	}
}