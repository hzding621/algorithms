import java.util.*;

public class Triangle {

	public static int minimumTotal(List<List<Integer>> triangle) {
		
		int n = triangle.size(); // depth of tree, which also should be the length of last depth
		int[] dp = new int[n];
		for (int i=0; i<n; i++)
			dp[i] = triangle.get(n-1).get(i);
		for (int i=n-1; i>=1; i--) {
			for (int j=0; j<i; j++) {
				dp[j] = Math.min(dp[j], dp[j+1]) + triangle.get(i-1).get(j);
			}
		}
		return dp[0];
	}

	public static void main(String[] args) {
		// test
		List<List<Integer>> ll = new ArrayList<List<Integer>>();
		List<Integer> l = new ArrayList<Integer>();
		l.add(2);
		ll.add(l);
		l = new ArrayList<Integer>();
		l.add(3); l.add(4);
		ll.add(l);
		l = new ArrayList<Integer>();
		l.add(6); l.add(5); l.add(7);
		ll.add(l);
		l = new ArrayList<Integer>();
		l.add(4); l.add(1); l.add(8); l.add(3);
		ll.add(l);

		System.out.println(minimumTotal(ll));
	}
}