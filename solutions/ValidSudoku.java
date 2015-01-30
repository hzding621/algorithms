// https://oj.leetcode.com/problems/valid-sudoku/

public class ValidSudoku {

	public static  boolean checkLine(char[][] board, int index, boolean isRow) {
		
		boolean[] table = new boolean[9];
		for (int i=0; i<9; i++) {
			char c;
			if (isRow == true) 
				c = board[index][i];
			else
				c = board[i][index];
			
			if (c != '.' && (c < '1' || c > '9') )
				return false;
				
			if (c >= '1' && c <= '9') {
				int num = c - '1';
				if (table[num] == true)
					return false;
				table[num] = true;
			}
		}
		return true;
	}
	
	public static  boolean checkSquare(char[][] board, int x, int y) {
		boolean[] table = new boolean[9];
		for (int i=0; i<3; i++) {
			for (int j=0; j<3; j++) {
				char c = board[x+i][y+j];
				if (c != '.' && (c < '1' || c > '9') )
					return false;
				if (c >= '1' && c <= '9') {
					int num = c - '1';
					if (table[num] == true)
						return false;
					table[num] = true;
				}
			}
		} 
		return true;
	}
	
	public static  boolean isValidSudoku(char[][] board) {
		for (int i=0; i<9; i++) {
			if (checkLine(board, i, true) == false)
				return false;
			if (checkLine(board, i, false) == false)
				return false;
		}
		boolean valid = checkSquare(board, 0, 0) && 
						checkSquare(board, 3, 3) &&
						checkSquare(board, 6, 6) &&
						checkSquare(board, 0, 3) &&
						checkSquare(board, 0, 6) && 
						checkSquare(board, 3, 6) &&
						checkSquare(board, 6, 3) &&
						checkSquare(board, 6, 0) &&
						checkSquare(board, 3, 0);
		return valid;
	}

	
}