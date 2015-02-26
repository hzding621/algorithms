import java.util.*;

public class TotalQueens {

	public static boolean checkValid(boolean[][] board, int row, int column) {
		for (int i=column+1; i<board.length; i++) {
			if (board[row][i] == true)
				return false;
			if (row-i+column>=0 && board[row-i+column][i] == true)
				return false;
			if (row+i-column<board.length && board[row+i-column][i] == true)
				return false;
		}
		return true;
	}

	public static int helper(boolean[][] board, int column) {

		if (column < 0) {
			return 1;
		}

		int sum = 0;
		for (int i=0; i<board.length; i++) {
			if (checkValid(board, i, column)) {
				board[i][column] = true;
				sum += helper(board, column-1);
				board[i][column] = false;
			}
		}
		return sum;
	}

	public static int totalNQueens(int n) {
		if (n < 2)
			return n;

		boolean[][] board = new boolean[n][n];
		return helper(board, board.length-1);
	}

	public static void main(String[] args) {
		for (int i=1; i<=15; i++)
			System.out.println(i+"x"+i+": "+totalNQueens(i));
	}
}