import java.util.*;

public class Combinations {

	// Use algorithm: 
	// Base case: 
	//				C(n,n) = [[1...n]] 
	//				C(n,0) = []
	// Recursive: 	
	//				C(n,k) = C(n-1,k) U C(n-1,k-1)

	public static List<List<Integer>> combine(int n, int k) {
		if (k == n || k == 0) {
			List<List<Integer>> ll = new ArrayList<List<Integer>>();
			ll.add(new ArrayList<Integer>());
			if (k == n)
				for (int i=1;i<=n; i++)
					ll.get(0).add(i);
			return ll;
		} 
		else {
			List<List<Integer>> ll1 = combine(n-1, k);
			List<List<Integer>> ll2 = combine(n-1, k-1);
			for (List<Integer> l: ll2)
				l.add(n);
			List<List<Integer>> ll = new ArrayList<List<Integer>>(ll1);
			ll.addAll(ll2);
			return ll;
		}
	}

	public static void main(String[] args) {
		List<List<Integer>> ll = combine(4,2);
		for (List<Integer> l: ll) {

			for (int i: l)
				System.out.print(i + " ");
			System.out.println();
			
		}
	}

}