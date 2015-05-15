import java.util.*;

public class PalindromePartition {

	public static List<List<String>> partition(String s) {

		int n = s.length();
		if (n == 0) {
			List<List<String>> l = new ArrayList<List<String>>();
			l.add(new ArrayList<String>());
			return l;
		}
		boolean[][] isPalindrome = new boolean[n][n];
		for (int i=0; i<n; i++)
			isPalindrome[i][i] = true;
		for (int i=0; i<n-1; i++) {
			isPalindrome[i][i+1] = s.charAt(i) == s.charAt(i+1);
		}
		for (int len=3; len<=n; len++) {
			for (int i=0; i<n-len+1; i++) {
				isPalindrome[i][i+len-1] = (s.charAt(i) == s.charAt(i+len-1)) && isPalindrome[i+1][i+len-2];
			}
		}

		List<List<String>>[] dp = new ArrayList[n+1];
		dp[0] = new ArrayList<List<String>>();
		dp[0].add(new ArrayList<String>());

		for (int i=1; i<=n; i++) {
			dp[i] = new ArrayList<List<String>>();
			for (int j=i; j>=1; j--) {
				if (isPalindrome[j-1][i-1]) {
					for (List<String> l: dp[j-1]) {
						List<String> newL = new ArrayList<String>(l);
						newL.add(s.substring(j-1, i));
						dp[i].add(newL);
					}
				}
			}
		}
		return dp[n];
	}

	public static void main(String[] args) {
		List<List<String>> ls = partition("aab");
		for (List<String> l : ls) {

			for (String s: l) {
				System.out.print(s+",");
			}
			System.out.println();
		}
	}
}