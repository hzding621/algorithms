public class JumpGameII {

	public static int jump(int[] nums) {

		// Breadth-First Search

		int start = 0, end = 0, nextEnd = 0;
		int steps = 0;
		while (end < nums.length - 1) {
			for (; start <= end; start++) {
				nextEnd = Math.max(nextEnd, nums[start] + start);
			}
			end = nextEnd;
			if (start > end)
				return Integer.MAX_VALUE;
			steps++;
		}
		return steps;
	}

	public static void main(String[] args) {
		int[] test = new int[] {2,1,1,0,4};
		System.out.println(jump(test));
	}
}