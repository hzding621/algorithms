import java.util.*;

public class WordBreak {

	public static boolean wordBreak(String s, Set<String> wordDict) {

		int n = s.length();
		if (n == 0)
			return true;

		boolean[][] isInSet = new boolean[n][n];
		for (int i = 0; i < n; i++) {
			for (int j = i; j < n; j++) {
				if (wordDict.contains(s.substring(i, j+1)))
					isInSet[i][j] = true;
			}
		}

		boolean[] dp = new boolean[n+1];
		dp[n] = true;
		for (int i = n-1; i>=0; i--) {
			for (int j = i; j < n; j++) {
				if (isInSet[i][j] && dp[j+1]) {
					dp[i] = true;
					break;
				}
			}
		}
		return dp[0];
	}

	public static void main(String[] args) {
		System.out.println(wordBreak("a", new HashSet<String>(Arrays.asList("a"))));
	}
}