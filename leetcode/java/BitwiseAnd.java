public class BitwiseAnd {
	
	public static int rangeBitwiseAnd(int m, int n) {
		// assume 0 <= m <= n <= INT_MAX
		if (m == 0)
			return 0;
		int zeros = 0;
		while (m != n) {
			m >>= 1;
			n >>= 1;
			zeros++;
		}
		return m << zeros;
	}

	public static void main(String[] args) {
		System.out.println(rangeBitwiseAnd(1, 2147483647));
	}

}


