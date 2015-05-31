import java.util.*;

public class ContainsDuplicateII {

	public static boolean containsNearbyDuplicate(int[] nums, int k) {
		HashSet<Integer> set = new HashSet<Integer>();
		for (int i=0; i<nums.length; i++) {
			if (i-k-1 >= 0)
				set.remove(nums[i-k-1]);
			if (set.contains(nums[i]))
				return true;
			set.add(nums[i]);
		}
		return false;
    }

	public static void main(String[] args) {
		int[] test = new int[] {1,2,1,3};
		System.out.println(containsNearbyDuplicate(test, 1));
	}
}