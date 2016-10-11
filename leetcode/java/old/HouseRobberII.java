public class HouseRobberII {

	public static int rob(int[] nums) {
		int n = nums.length;
		if (n == 0)
			return 0;
		if (n == 1)
			return nums[0];

		int[] dp = new int[n];
		int backup = nums[n-1];
		nums[n-1] = 0;

		int max = 0;

		// once
		dp[n-1] = nums[n-1];
		dp[n-2] = Math.max(nums[n-1], nums[n-2]);
		for (int i=n-3; i>=0; i--) {
			dp[i] = Math.max(dp[i+1], nums[i]+dp[i+2]);
		}
		max = dp[0];

		nums[n-1] = backup;
		backup = nums[0];
		nums[0] = 0;

		// twice
		dp[n-1] = nums[n-1];
		dp[n-2] = Math.max(nums[n-1], nums[n-2]);
		for (int i=n-3; i>=0; i--) {
			dp[i] = Math.max(dp[i+1], nums[i]+dp[i+2]);
		}
		max = Math.max(max, dp[0]);
		return max;

	}

	public static void main(String[] args) {
		
	}
}