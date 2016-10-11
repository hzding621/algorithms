import java.util.*;

public class ThreeSumClosest {

	public static int threeSumClosest(int[] nums, int target) {
		Arrays.sort(nums);
		int global_closets = nums[0]+nums[1]+nums[2];
		for (int k=0; k<nums.length; k++) {
			int t = target - nums[k];
			int i = (k == 0) ? 1 : 0;
			int j = (k == nums.length-1)? (nums.length-2) : (nums.length-1);
			int closest = nums[i]+nums[j]+nums[k];
			while (i != j) {
				int better = nums[i]+nums[j]+nums[k];
				if (Math.abs(better-target) < Math.abs(closest-target))
					closest = better;
				if (nums[i]+nums[j]==t)
					return target;
				else if (nums[i]+nums[j]>t) {
					j--;
					if (j == k)
						j--;
				} else {
					i++;
					if (i == k)
						i++;
				}
			}
			if (Math.abs(global_closets-target) > Math.abs(closest-target))
				global_closets = closest;
		}
		return global_closets;
	}

	public static void main(String[] args) {
		int[] input = {-1, 2, 1, -4};
		System.out.println(threeSumClosest(input, 1));
	}

}