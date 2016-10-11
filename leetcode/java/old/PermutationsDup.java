import java.util.*;

public class PermutationsDup {


	static List<List<Integer>> permuteUniqueRecursion(int[] nums, boolean[] used) {
		
		List<List<Integer>> ll = new ArrayList<List<Integer>>();
		HashSet<Integer> unique = new HashSet<Integer>();
		List<List<Integer>> ret = new ArrayList<List<Integer>>();
		boolean empty = true;
		for (int i=0; i<used.length; i++) {
			if (used[i] == false && !unique.contains(nums[i])) {
				empty = false;
				unique.add(nums[i]);
				used[i] = true;
				List<List<Integer>> rec = permuteUniqueRecursion(nums, used);
				used[i] = false;
				for (List<Integer> l : rec) {
					l.add(nums[i]);
				}
				ret.addAll(rec);
			}
		}
		if (empty)
			ret.add(new ArrayList<Integer>());
		return ret;
	}

	public static List<List<Integer>> permuteUnique(int[] nums) {
		return permuteUniqueRecursion(nums, new boolean[nums.length]);
	}

	public static void main(String[] args) {
		List<List<Integer>> ls = permuteUnique(new int[] {1,1,2,2});
		for (List<Integer> l :ls) {
			System.out.print('[');
			for (int i: l)
				System.out.print(i + " ");
			System.out.println(']');
		}
	}
}