import java.util.*;

public class PermutationSequence {

	public static int factorial(int n) {
		int product = 1;
		while (n > 1) {
			product *= n;
			n--;
		}
		return product;
	}

	public static String getPermutation(int n, int k) {
        List<Integer> l = new ArrayList<Integer>();
        k = k - 1;
        for (int i = 1; i <= n; i++)
        	l.add(i);
        StringBuilder sb = new StringBuilder();
        while (n > 0) {

        	int div = factorial(n-1);
        	int p = k / div;
        	sb.append(l.get(p));
        	l.remove(p);
        	k = k % div;
        	n--;
        }
        return sb.toString();
    }

    public static void main(String[] args) {
    	/*
			1234 1
			1243 2
			1324 3
			1342 4
			1423 5
			1432 6

    	*/

		System.out.println(getPermutation(9, 2));
    }
}