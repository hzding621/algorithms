public class JumpGame {

	public static boolean canJump(int[] nums) {
		int n = nums.length;
		boolean[] dp = new boolean[n];
		dp[n-1] = true;
		for (int i=n-2; i>=0; i--) {
			if (i + nums[i] >= n-1)
				dp[i] = true;
			else if (nums[i] == 1+nums[i+1])
				dp[i] = dp[i+1];
			else {
				int a = i+1+nums[i+1]+1;
				int b = i+nums[i];
				for (int k=a; k<=b; k++) {
					if (k < n)
						dp[i] = dp[i] || dp[k];
				}
				if (nums[i] > 0)
					dp[i] = dp[i] || dp[i+1];
			}
		}
		return dp[0];
	}

	public static void main(String[] args) {
		int[] input = {1,1,2,2,0,1,1};
		System.out.println(canJump(input));
	}
}