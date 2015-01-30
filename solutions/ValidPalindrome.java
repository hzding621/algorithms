public class ValidPalindrome {

	public static String preprocess(String s) {
		StringBuilder sb = new StringBuilder();
		for (int i=0; i<s.length(); i++) {
			char c = s.charAt(i);
			if (Character.isLetterOrDigit(c))
				sb.append(Character.toLowerCase(c));
		}
		return sb.toString();
	}
	
	public static boolean isPalindromeHelper(String s) {
		int length = s.length()-1;
		for (int i=0; i<(length+1)/2; i++) {
			if (s.charAt(i) != s.charAt(length-i))
				return false;
		}
		return true;
	}
	
	public static boolean isPalindrome(String s) {
		return isPalindromeHelper(preprocess(s));
	}

}