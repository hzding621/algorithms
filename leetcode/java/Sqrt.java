public class Sqrt {
	public static int mySqrt(int x) {
		if ( x == 0)
			return 0;
		else if ( x < 4)
			return 1;
		else if ( x < 6)
			return 2;
		long i = 1, j = x/2;
		while (i + 1 < j) {
			long m = (i + j) / 2;
			if ( m * m == x)
				return (int) m;
			else if ( m * m < x)
				i = m;
			else
				j = m;
		}
		return (int)i;

	}

	public static void main(String[] args) {
		for (int i = 1; i < 100; i++)
			System.out.println(i + ": " + mySqrt(i));
		System.out.println(mySqrt(2147483647));
	}
}