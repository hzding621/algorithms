class Result {
	public int maxFullPath;
	public int maxHalfPath;
	public Result(int a, int b) {
		maxFullPath = a;
		maxHalfPath = b;
	}
} 

class MaxPathSum {
	public static int maxPathSum(TreeNode root) {
		Result r = compute(root);
		return r.maxFullPath;
	}
	
	static Result compute(TreeNode root) {
		if (root == null) {
			return new Result(Integer.MIN_VALUE, Integer.MIN_VALUE);
		}
		int a = root.val, b = root.val;
		Result r1 = compute(root.left);
		Result r2 = compute(root.right);
		if (root.left != null) {
			a = Math.max(a, r1.maxFullPath);
			a = Math.max(a, root.val + r1.maxHalfPath);
			b = Math.max(b, root.val + r1.maxHalfPath);
		}
		if (root.right != null) {
			a = Math.max(a, r2.maxFullPath);
			a = Math.max(a, root.val + r2.maxHalfPath);
			b = Math.max(b, root.val + r2.maxHalfPath);
		}
		if (root.left != null && root.right != null) {
			a = Math.max(a, root.val + r1.maxHalfPath + r2.maxHalfPath);
		}
		return new Result(a, b);
	}

	public static void main(String[] args) {
		TreeNode tn = new TreeNode("1 2 * * 3 * *");
		System.out.println(maxPathSum(tn));
	}


}
