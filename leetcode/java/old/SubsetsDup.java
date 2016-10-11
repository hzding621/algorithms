import java.util.*;

public class SubsetsDup {

	public static List<List<Integer>> subsetsWithDup(int[] nums) {
        
		TreeMap<Integer, Integer> multiset = new TreeMap<Integer,Integer>();
		for (int i : nums) {
			if (multiset.containsKey(i))
				multiset.put(i, multiset.get(i)+1);
			else
				multiset.put(i, 1);
		}

		List<List<Integer>> ret = new ArrayList<List<Integer>>();
		List<Integer> empty = new ArrayList<Integer>();
		ret.add(empty);

		for (int i: multiset.keySet()) {
			List<List<Integer>> newLists = new ArrayList<List<Integer>>();
			for (int c = 1; c <= multiset.get(i); c++) {
				for (List<Integer> l : ret) {
					List<Integer> newList = new ArrayList<Integer>(l);
					for (int k=0; k<c; k++)
						newList.add(i);
					newLists.add(newList);
				}
			}
			ret.addAll(newLists);
		}

		return ret;
    }

	public static void main(String[] args) {
		int[] input = {1,2,3};
		List<List<Integer>> s = subsetsWithDup(input);
		for (List<Integer> l : s)  {
			for (int i: l)
				System.out.print(i+" ");
			System.out.println();
		}
	}
}