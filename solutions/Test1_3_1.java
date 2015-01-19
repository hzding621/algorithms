public class Test1_3_1 {

	public static boolean isPermutation(String x, String y) {
		// determin whether x is a permutation of y

		int xlen = x.length();
		int ylen = y.length();

		if (xlen == 0)
			return true;
		if (ylen == 0)
			return false;

		if (xlen % ylen != 0)
			return false;

		int i=0, j=0;
		while (i < xlen)
		{
			while (j < ylen)
			{
				if (x.charAt(i) != y.charAt(j))
					return false;
				j++;
				i++;
			}
			j=0;
		}
		return true;

	}

	public static void main(String[] args) {
		System.out.println("isPermutation(\"xxx\", \"x\"): " + isPermutation("xxx", "x"));
		System.out.println("isPermutation(\"xxy\", \"x\"): " + isPermutation("xxy", "x"));
		System.out.println("isPermutation(\"abcabcabc\", \"abc\"): " + isPermutation("abcabcabc", "abc"));
		System.out.println("isPermutation(\"abcabc\", \"ab\"): " + isPermutation("abcab", "ab"));
	}



}