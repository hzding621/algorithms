import java.util.*;

public class SeedNumber {

	public static List<Integer> findSeeds(int n) {

		List<Integer> factors = findFactors(n);
		List<Integer> seeds = new ArrayList<Integer>();
		for (int k : factors) {
			int f = k;
			int temp = k;
			while (k > 0) {
				temp *= k % 10;
				k /= 10;
			}
			if (temp == n)
				seeds.add(f);
		}
		return seeds;

	}

	public static List<Integer> findFactors(int n) {
		List<Integer> factors = new ArrayList<Integer>();
		for (int i=2; i<=n/2; i++) {
			if (n % i == 0)
				factors.add(i);
		}
		return factors;
	}

	public static void printList(List<Integer> list) {
		System.out.print('[');
		for (int i=0; i<list.size()-1; i++)
			System.out.print(list.get(i) + ", ");
		System.out.println(list.get(list.size()-1) + "]");
	}

	public static void main(String[] args) {
		printList(findSeeds(24));
		printList(findSeeds(1716));
	}

}