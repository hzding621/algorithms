public class UniquePathsObstacles {

	static int dp(int[][] table, int m, int n, int x, int y, int[][] obstacleGrid){

		if (obstacleGrid[x][y] == 1)
			return 0;

		if (x == m-1 && y == n-1) {
			return 1;
		}
		
		if (x == m-1)
			return table[m-1][y+1];
		if (y == n-1)
			return table[x+1][n-1];
		return table[x+1][y] + table[x][y+1];
	}
	
	
	public static int uniquePathsWithObstacles(int[][] obstacleGrid) {
		
		int m = obstacleGrid.length;
		int n = obstacleGrid[0].length;

		if (m == 0 || n == 0)
			return 0;

		int[][] table = new int[m][n];
		for (int x=m-1; x >= 0; x--) {
			for (int y=n-1; y >= 0; y--) {
				table[x][y] = dp(table, m, n, x, y, obstacleGrid);
			}
		}
		
		return table[0][0];
	}

	public static void main(String[] args) {
		int[][] o = new int[][] {
			{0,0,0},
			{0,1,0},
			{0,1,0}
		};
		Helpers.print(o);
		System.out.println(">> "+uniquePathsWithObstacles(o));
	}

}