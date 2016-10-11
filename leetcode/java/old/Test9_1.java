import java.util.HashMap;

public class Test9_1 {

	static HashMap<Long, Long> table;

	public static long solve(long n) {
		
		if (table == null)
			table = new HashMap<Long, Long>();

		if (table.containsKey(n))
			return table.get(n);

		long res;

		if (n == 1)
			res = 1;
		else if (n == 2)
			res = 2;
		else if (n == 3)
			res = 4;
		else
			res = 3+solve(n-1)+solve(n-2)+solve(n-3);
		table.put(n, res);
		return res;

	}

	public static void main(String []args) {

		System.out.println("Solve(5): " + solve(5));
		System.out.println("Solve(10): " + solve(10));
		System.out.println("Solve(30): " + solve(30));

	}

}