public class Stock {
	public static int maxProfit(int[] prices) {
		if (prices.length == 0)
			return 0;

		int[] minUntil = new int[prices.length];
		minUntil[0] = 0;
		for (int i=1; i<prices.length; i++) {
			minUntil[i] = prices[minUntil[i-1]] < prices[i] ? minUntil[i-1] : i;
		} 
		int maxDiff = 0;
		for (int i=1; i<prices.length; i++) {
			maxDiff = Math.max(maxDiff, prices[i] - prices[minUntil[i]]);
		}
		return maxDiff;
	}



	public static void main(String[] args) {
		int[] prices = new int[] {2,5,1,3,7,8,4};
		System.out.println(maxProfit(prices));
	}
}