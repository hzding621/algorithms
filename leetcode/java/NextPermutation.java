public class NextPermutation {

	static void swap(int[] nums, int i, int j) {
		int t = nums[i];
		nums[i] = nums[j];
		nums[j] = t;
	}

	static void sort(int[] nums, int i, int j) {
		// quick sort
		if (i >= j)
			return;
		int mid = nums[(i+j)/2];
		swap(nums, (i+j)/2, j);
		int t = i;
		for (int k=i; k<=j-1; k++) {
			if (nums[k] <= mid) {
				swap(nums, t, k);
				t++;
			}
		}
		swap(nums, t, j);
		sort(nums, i, t-1);
		sort(nums, t+1, j);
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
				if (nums[k] > ini && nums[k] < nums[next])
					next = k;
			}
			swap(nums, i-1, next);
			sort(nums, i, nums.length-1);
		} else {
			swap(nums, 0, nums.length-1);
			sort(nums, 1, nums.length-1);
		}
		return;
	}

	public static void main(String[] args) {
		int[] num = {1,2,3,4,5};
		int times = 121;
		while (times > 0) {
			times--;
			Helpers.print(num);
			nextPermutation(num);
		}
	}
}