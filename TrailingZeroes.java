public class TrailingZeroes {
	public static int trailingZeroes(int n) {
		if (n < 5)
			return 0;
		
		int count = 0;
		int exponent = (int) (Math.log(n)/Math.log(5));
		for (int i=1; i<=exponent; i++) {
			int factor = (int) Math.pow(5, i);
			int appears = n / factor;
			count += appears;
		}
		return count;
	}

	public static void main(String[] args) {
		System.out.println(trailingZeroes(30));
	}
}