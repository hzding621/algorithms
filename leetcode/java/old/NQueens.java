import java.util.*;

public class NQueens {

	static boolean checkValidLeft(boolean[][] board, int m, int n) {
		for (int j=0; j<n; j++) {
			if (board[m][j] == true)
				return false;
			if (m-n+j>=0 && board[m-n+j][j] == true)
				return false;
			if (m+n-j<board.length && board[m+n-j][j] == true)
				return false;
		}
		return true;
	}

	static String[] transform(boolean[][] board) {
		String[] ret = new String[board.length];
		for (int i=0; i<board.length; i++) {
			StringBuilder sb = new StringBuilder();
			for (int j=0; j<board.length; j++) {
				if (board[i][j]) {
					sb.append('Q');
				} else {
					sb.append('.');
				}
			}
			ret[i] = sb.toString();
		}
		return ret;
	}

	static List<String[]> recurse(boolean[][] board, int n) {

		List<String[]> ret = new ArrayList<String[]>();
		for (int i=0; i<board.length; i++) {
			if (checkValidLeft(board, i, n)) {
				board[i][n] = true;
				if (n == board.length-1) {
					String[] t = transform(board);
					ret.add(t);
				} else {
					List<String[]> rec = recurse(board, n+1);
					ret.addAll(rec);
				}
				board[i][n] = false;
			}
		}
		return ret;
	}

	public static List<String[]> solveNQueens(int n) {
		boolean[][] board = new boolean[n][n];
        return recurse(board, 0);
    }

	public static void main(String[] args) {
		int n = 8;
		List<String[]> ans = solveNQueens(n);
		for (String[] ss : ans) {
			for (String s: ss) {
				System.out.println(s);
			}
			System.out.println('\n');
		}
		System.out.println("There are a total of "+ans.size()+" solutions for N = "+n+".");
	}
}