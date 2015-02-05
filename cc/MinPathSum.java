// https://oj.leetcode.com/problems/minimum-path-sum/

public class MinPathSum {


	static int dp(int[][] grid, int[][] dpTable, int x, int y) {

		int ylen = grid[0].length;
		int xlen = grid.length;

		if (x == xlen-1 && y == ylen-1)
			return grid[x][y];
		else if (x == xlen-1)
			return dpTable[x][y+1] + grid[x][y];
		else if (y == ylen-1)
			return dpTable[x+1][y] + grid[x][y];
		return Math.min(dpTable[x+1][y], dpTable[x][y+1]) + grid[x][y];

	}

	static int dpFill(int[][] grid) {

		int ylen = grid[0].length;
		int xlen = grid.length;

		int[][] dpTable = new int[xlen][ylen];

		for (int i=xlen-1; i>=0; i--) {
			for (int j=ylen-1; j>=0; j--) {
				dpTable[i][j] = dp(grid, dpTable, i, j);
			}
		}
		return dpTable[0][0];
	}

	public static int compute(int[][] grid) {

		if (grid.length == 0 || grid[0].length == 0) 
			return 0;
		return dpFill(grid);

	}

	public static void main(String[] args) {

		int[][] grid = new int[][] {
			{0,0,0},
			{1,1,0},
			{1,1,1}
		};

		System.out.println(compute(grid));


	}

}