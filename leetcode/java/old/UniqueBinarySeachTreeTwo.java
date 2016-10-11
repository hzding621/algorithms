import java.util.*;

public class UniqueBinarySeachTreeTwo {
	public static List<TreeNode> generateTrees(int n) {

		if (n == 0) {
            ArrayList<TreeNode> r = new ArrayList<TreeNode>();
            r.add(null);
            return r;
        }

		ArrayList<TreeNode>[][] dp = new ArrayList[n][n];
		for (int i=0; i<n; i++) {
			for (int j=0; j<n; j++) {
				if (j < i)
					dp[i][j] = null;
				else 
					dp[i][j] = new ArrayList<TreeNode>();
			}
		}
		for (int i=0; i<n; i++) {
			dp[i][i].add(new TreeNode(i+1)); // simple node tree
		}
		for (int len=2; len<=n; len++) {
			for (int i=0; i<n; i++) {
				int j=i+len-1;
				if (j < n) {
					// root is i
					for (TreeNode rc: dp[i+1][j]) {
						TreeNode nn = new TreeNode(i+1);
						nn.right = rc;
						dp[i][j].add(nn);
					}
					// root is j
					for (TreeNode lc: dp[i][j-1]) {
						TreeNode nn = new TreeNode(j+1);
						nn.left = lc;
						dp[i][j].add(nn);
					}
					// root is in (i, j)
					for (int rt=i+1; rt<=j-1; rt++) {
						for (TreeNode lc: dp[i][rt-1]) {
							for (TreeNode rc: dp[rt+1][j]) {
								TreeNode nn = new TreeNode(rt+1);
								nn.left = lc;
								nn.right = rc;
								dp[i][j].add(nn);
							}
						}
					}
				}
			}
		
		}
		return dp[0][n-1];
	}
	public static void main(String[] args) {
		List<TreeNode> ll = generateTrees(3);
		for (TreeNode t: ll) {
			t.print();
		}
	}

}