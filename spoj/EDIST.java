import java.util.*;

public class EDIST {
	public static void main(String[] args) {
		Scanner stdin = new Scanner(System.in);
		int num = stdin.nextInt();

		while (num > 0) {
			String a = stdin.next();
			String b = stdin.next();

			int[][] table = new int[a.length()+1][b.length()+1];

			table[a.length()][b.length()] = 0;
			for (int i=a.length(); i>=0; i--) {
				for (int j=b.length(); j>=0; j--) {
					if (i == a.length() && j == b.length() )
						continue;

					int min = Integer.MAX_VALUE;
					if (i < a.length())
						min = Math.min(min, table[i+1][j]);
					if (j < b.length())
						min = Math.min(min, table[i][j+1]);

					table[i][j] = min + 1;

					int min2 = Integer.MAX_VALUE;
					if (i < a.length() && j < b.length()) {
						min2 = table[i+1][j+1] + (a.charAt(i) == b.charAt(j) ? 0 : 1);
					}


					table[i][j] = Math.min(table[i][j], min2);
				}
			}

			System.out.println(table[0][0]);
			num--;
		}
	}
}