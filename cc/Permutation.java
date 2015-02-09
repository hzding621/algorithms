import java.util.*;

public class Permutation {

	public static List<List<Integer>> permute(int[] num) {
		List<List<Integer>> result = new ArrayList<List<Integer>>();
		result.add(new ArrayList<Integer>());
		for (int i=0; i<num.length; i++) {

			List<List<Integer>> current = new ArrayList<List<Integer>>();
			for (List<Integer> l : result) {
				for (int j=0; j<=l.size(); j++) {
					ArrayList<Integer> temp = new ArrayList<Integer>(l);
					temp.add(j, num[i]);
					current.add(temp);
				}
			}
			result = current;
		}
		return result;
	}

	public static void main(String[] args) {
		List<List<Integer>> result = permute(new int[]{1,2,3});
		for (List<Integer> l :result) {
			System.out.print('[');
			for (int i: l)
				System.out.print(i + " ");
			System.out.println(']');
		}

	}

}