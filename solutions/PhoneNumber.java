import java.util.*;

public class PhoneNumber {

	/*.
	Print all valid phone numbers of length n subject to following constraints:
	1.If a number contains a 4, it should start with 4
	2.All digits are distinct
	3.Three digits (e.g. 7,2,9) will be entirely disallowed, take as input
	*/

	public static boolean checkDistinct(List<Integer> list) {
		if (list.size() > 10)
			return false;
		boolean[] array = new boolean[10];
		for (int i : list) {
			if (array[i] == true)
				return false;
			array[i] = true;
		}
		return true;
	}

	public static List<List<Integer>> compute(List<Integer> disallowed, int n) {
		List<List<Integer>> perm = permute(n);
		return teleCheck(perm, disallowed);
	}

	public static List<List<Integer>> teleCheck(List<List<Integer>> permute, List<Integer> disallowed){

		List<List<Integer>> ret = new ArrayList<List<Integer>>();

		for (List<Integer> l : permute) {
			boolean add = true;

			if (checkDistinct(l) == false) {
				add = false;
				continue;
			}

			for (int i=0; i<l.size(); i++) {
				int num = l.get(i);

				if (num == 4 && i != 0) {
					add = false;
					break;
				}

				for (int j=0; j<disallowed.size(); j++) {
					if (disallowed.get(j) == num) {
						add = false;
						break;
					}
				}

				if (add == false)
					break;
			}

			if (add == true)
				ret.add(l);
		}

		return ret;


	}


	public static List<List<Integer>> permute(int n) {
		/* generate all lists of length n */

		List<List<Integer>> ret = new ArrayList<List<Integer>>();

		if (n == 0)
			return ret;


		for (int i=0; i<10; i++) {
			List<Integer> newItem = new ArrayList<Integer>();
			newItem.add(i);
			ret.add(newItem);
		}
		n--;
		while (n > 0) {

			List<List<Integer>> cache = new ArrayList<List<Integer>>();

			for (List<Integer> l: ret) {
				for (int i=1; i<10; i++) {
					List<Integer> newL =  new ArrayList<Integer>(l);
					newL.add(i);
					cache.add(newL);
				}
				l.add(0);
			}

			for (List<Integer> m: cache)
				ret.add(m);
			n--;
		}

		return ret;

	}

	public static void printList(List<Integer> list) {
		
		System.out.print("[");
		for (int i=0; i<list.size() - 1; i++) {
			System.out.print(list.get(i) + ",");
		}
		System.out.println(list.get(list.size()-1) + "]"); 
	}

	public static void printDoubleList(List<List<Integer>> lists) {
		for (List<Integer> l: lists) {
			printList(l);
		}
	}

	public static void main(String[] args) {
		List<Integer> disallowed = new ArrayList<Integer>();

		disallowed.add(0);
		disallowed.add(1);
		disallowed.add(2);
		disallowed.add(3);
		disallowed.add(5);
		disallowed.add(6);

		List<List<Integer>> ret = compute(disallowed, 3);
		printDoubleList(ret);
	}

}