// https://oj.leetcode.com/problems/unique-paths/

public class UniquePath {

	static int dp(int[][] table, int m, int n, int x, int y){
		if (x == m-1 && y == n-1) {
			return 1;
		}
		
		if (x == m-1)
			return table[m-1][y+1];
		if (y == n-1)
			return table[x+1][n-1];
		return table[x+1][y] + table[x][y+1];
	}
	
	
	public static int uniquePaths(int m, int n) {
		
		int[][] table = new int[m][n];
		for (int x=m-1; x >= 0; x--) {
			for (int y=n-1; y >= 0; y--) {
				table[x][y] = dp(table, m, n, x, y);
			}
		}
		
		return table[0][0];
	}

	public static void main(String[] args) {
		System.out.println(uniquePaths(2,2));
	}


}