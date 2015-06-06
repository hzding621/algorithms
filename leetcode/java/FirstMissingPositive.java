public class FirstMissingPositive {
    public static int firstMissingPositive(int[] nums) {
        for (int i = 0; i < nums.length; i++) {
			while (nums[i] != i+1) {
				if (nums[i] <= 0 || nums[i] > nums.length || nums[i] == nums[nums[i]-1]) break;
				swap(nums, i, nums[i]-1);
			}
		}
		for (int i = 0; i<nums.length; i++) {
			if (nums[i] != i+1)
				return i+1;
		}
        return nums.length+1;
	}
	
	static void swap(int[] nums, int i, int j) {
		int t = nums[i];
		nums[i] = nums[j];
		nums[j] = t;
	}

	public static void main(String[] args) {
		
	}
}