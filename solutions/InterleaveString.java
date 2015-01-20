// https://oj.leetcode.com/problems/interleaving-string/

public class InterleaveString {

	static boolean isInterleave(String s1, String s2, String s3) {
		if (s3 == null || s1 == null || s2 == null)
			return false;

		if (s1.length() == 0) {
			if (s3.equals(s2))
				return true;
			else
				return false;
		}
		if (s2.length() == 0) {
			if (s3.equals(s1)) 
				return true;
			else
				return false;
		}

		/* both s1 and s2 are non-empty */
		if (s1.length() + s2.length() != s3.length())
			return false;

		int len1 = s1.length();
		int len2 = s2.length();
		boolean[][] memoize = new boolean[len1+1][len2+1];
		
		memoize[len1][len2] = true;
		for (int i=len1-1; i>=0; i--)
			memoize[i][len2] = memoize[i+1][len2] && (s3.charAt(i+len2) == s1.charAt(i));
		for (int j=len2-1; j>=0; j--)
			memoize[len1][j] = memoize[len1][j+1] && (s3.charAt(len1+j) == s2.charAt(j));
		for (int i=len1-1; i>=0; i--) {
			for (int j=len2-1; j>=0; j--) {
				boolean backtrack = (memoize[i+1][j] && s3.charAt(i+j) == s1.charAt(i)) 
								 || (memoize[i][j+1] && s3.charAt(i+j) == s2.charAt(j));
				memoize[i][j] = backtrack;
			}
		}

		return memoize[0][0];

	}

	public static void main(String[] args) {
		boolean result = isInterleave("ba", "bb", "abab");
		System.out.println(result);
	}
}