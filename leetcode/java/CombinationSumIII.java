import java.util.*;

public class CombinationSumIII {

	static List<List<Integer>> helper(int k, int n, int largest) {
		List<List<Integer>> ans = new ArrayList<List<Integer>>();
		if (n > 0 && k > 0 && largest > 0) {
			for (int i = 1; i<=largest; i++) {
				List<List<Integer>> backtrack = helper(k-1, n-i, i-1);
				for (List<Integer> ls : backtrack) {
					ls.add(i);
				}
				ans.addAll(backtrack);
			}
		} else if (n == 0 && k == 0) {
			ans.add(new ArrayList<Integer>());
		}
		return ans;
	}

	public static List<List<Integer>> combinationSum3(int k, int n) {
		return helper(k, n, 9);
	}

	public static void main(String[] args) {
		List<List<Integer>> ll = combinationSum3(3, 9);
		for (List<Integer> l : ll) {
			System.out.println(l.toString());
		}
	}
}