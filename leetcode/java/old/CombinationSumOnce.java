import java.util.*;

public class CombinationSumOnce {


	static List<List<Integer>> combinationSum2Helper(int[] unique, int[] remain, int target, int index) {
		
		List<List<Integer>> ret = new ArrayList<List<Integer>>();
		if (target == 0) {
			ret.add(new ArrayList<Integer>());
		}
		else if (target > 0) {
			for (int i=index; i<unique.length; i++) {
				
				if (remain[i] > 0) {
					remain[i] = remain[i]-1;
					List<List<Integer>> partial = combinationSum2Helper(unique, remain, target - unique[i], i);
					for (List<Integer> l : partial) {
						l.add(unique[i]);
						ret.add(l);
					}
					remain[i] = remain[i]+1;
				}
			}
		}
		return ret;
	}

	public static List<List<Integer>> combinationSum2(int[] candidates, int target) {
		TreeMap<Integer, Integer> hash = new TreeMap<Integer, Integer>();
		for (int i: candidates) {
			if (hash.containsKey(i))
				hash.put(i, hash.get(i)+1);
			else
				hash.put(i, 1);
		}

		int[] unique = new int[hash.size()];
		int[] remain = new int[hash.size()];
		int j = 0;
		for (int i: hash.descendingKeySet()) {
			unique[j] = i;
			remain[j] = hash.get(i);
			j++;
		}
		return combinationSum2Helper(unique, remain, target, 0);
	}

	public static void main(String[] args) {
		int[] input = new int[] {10,1,2,7,6,1,5};
		List<List<Integer>> ll = combinationSum2(input, 8);
		for (List<Integer> l : ll)
			System.out.println(l.toString());
	}
}