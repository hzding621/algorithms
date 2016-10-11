public class SearchRange {

	static int binarySearchLower(int[] array, int low, int high, int target) {
		
		if (low == high)
			return array[low] == target ? low : -1;
		else if (low + 1 == high) {
			if (array[low] == target)
				return low;
			else if (array[high] == target)
				return high;
			else
				return -1;
		} else {

			int mid = (low + high) / 2;
			if (array[mid] == target && array[mid-1] < target)
				return mid;
			else if (array[mid] < target) 
				return binarySearchLower(array, mid+1, high, target);
			else
				return binarySearchLower(array, low, mid-1, target);
		}
	}

	static int binarySearchHigher(int[] array, int low, int high, int target) {
		if (low == high) {
			return array[low] == target ? low : -1;
		} else if (low + 1 == high) {
			if (array[high] == target)
				return high;
			else if (array[low] == target)
				return low;
			else 
				return -1;
		} else {
			int mid = (low + high) / 2;
			if (array[mid] == target && array[mid+1] > target)
				return mid;
			else if (array[mid] > target) 
				return binarySearchHigher(array, low, mid-1, target);
			else 
				return binarySearchHigher(array, mid+1, high, target);
		}
	}

	public static int[] searchRange(int[] nums, int target) {
		int[] ret = {-1, -1};
		ret[0] = binarySearchLower(nums, 0, nums.length-1, target);
		ret[1] = binarySearchHigher(nums, 0, nums.length-1, target);
		return ret;
	}

	public static void main(String[] args) {
		int[] input = {5, 7, 7, 8, 8, 10};
		int[] res = searchRange(input, 8);
		System.out.println(res[0] + " " + res[1]);
	}
}