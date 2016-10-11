public class NextPermutation {

	static void swap(int[] nums, int i, int j) {
		int t = nums[i];
		nums[i] = nums[j];
		nums[j] = t;
	}

	static void reverse(int[] nums, int i, int j) {
		for (int k=i; k<=(i+j)/2; k++) {
			swap(nums, k, i+j-k);
		}
	}

	public static void nextPermutation(int[] nums) {
		if (nums.length == 1)
			return;
		int i=nums.length-1;
		for (; i>=1; i--) {
			if (nums[i] > nums[i-1]) {
				break;
			}
		}

		if (i > 0) {
			int ini = nums[i-1];
			int next = i;
			for (int k=i; k<=nums.length-1; k++) {
				if (nums[k] > ini && nums[k] <= nums[next]) // must swap to the right-most position to preserve non-increasing order
					next = k;
			}
			swap(nums, i-1, next);
			reverse(nums, i, nums.length-1);
		} else {
			reverse(nums, 0, nums.length-1);
		}
		return;
	}

	public static void main(String[] args) {
		int[] num = {1,2,3,4};
		int times = 25;
		while (times > 0) {
			times--;
			Helpers.print(num);
			nextPermutation(num);
		}
	}
}