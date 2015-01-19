public class Test1_3 {

	public static String sort(String x) {
		char[] str = x.toCharArray();
		java.util.Arrays.sort(str);
		return new String(str);
	}

	public static boolean isPermutation(String x, String y) {
		if (x.length() != y.length())
			return false;

		return sort(x).equals(sort(y));

	}

	public static boolean isPermutationHash(String x, String y) {
		if (x.length() != y.length() )
			return false;

		char[] letters = new char[256];
		char[] content = x.toCharArray();
		for (char c: content)
			letters[c]++;

		char[] content2 = y.toCharArray();
		for (char c: content2)
		{
			letters[c]--;
			if (letters[c] < 0)
				return false;
		}
		return true;
	}


	public static void main(String[] args) {
		System.out.println("isPermutationHash(\"xyz\", \"xzy\"): " + isPermutationHash("xyz", "xzy"));
		System.out.println("isPermutationHash(\"abc\", \"abcd\"): " + isPermutationHash("abc", "abcd"));
		System.out.println("isPermutationHash(\"abcdefg\", \"abdcfeg\"): " + isPermutationHash("abdcfeg", "abcdefg"));
	}
		
}