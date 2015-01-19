public class Test9_8 {

	public static int coin(int n, int denom) {
		int next_denom = 0;
		switch (denom) {
			case 25:
				next_denom = 10;
				break;
			case 10:
				next_denom = 5;
				break;
			case 5:
				next_denom = 1;
				break;
			case 1:
				return 1;
		}
		int ways = 0;
		for (int j=0; j * denom <= n; j++){
			ways += coin(n - j*denom, next_denom);
		}
		return ways;
	}
	public static void main(String[] args) {
		System.out.println("coin(10): " + coin(100, 25));
	}

}