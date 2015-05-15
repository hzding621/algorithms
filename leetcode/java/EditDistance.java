public class EditDistance {


	public static int minDistance(String word1, String word2) {
		int m = word1.length();
		int n = word2.length();
		int[][] dp = new int[m+1][n+1];
		for (int k = 0; k<=n; k++) {
			dp[0][k] = k;
		}
		for (int k = 0; k<=m; k++) {
			dp[k][0] = k;
		}
		for (int i = 1; i<=m; i++) {
			for (int j = 1; j<=n; j++) {
				dp[i][j] = Math.min(1+dp[i-1][j], 1+dp[i][j-1]); // insert or delete
				dp[i][j] = Math.min(dp[i][j], 1+dp[i-1][j-1]); // replace
				if (word1.charAt(i-1) == word2.charAt(j-1))
					dp[i][j] = Math.min(dp[i][j], dp[i-1][j-1]);
			}
		}
		return dp[m][n];
	}

	public static void main(String[] args) {

	}
}