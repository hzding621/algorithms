import java.util.*;
import java.io.*;

public class COINS {

	static HashMap<Integer, Long> map = new HashMap<Integer, Long>();


	public static long solve(int n) {
		if (map.containsKey(n))
			return map.get(n);
		long ans;
		if (n == 0)
			ans = 0;
		else
			ans = Math.max(n, solve(n/2) + solve(n/3) + solve(n/4));
		
		map.put(n, ans);
		return ans;

	}

	public static void main(String[] args) throws IOException {

		Scanner stdin = new Scanner(System.in);
		while (stdin.hasNext()) {
			System.out.println(solve(stdin.nextInt()));
		}

	}

}