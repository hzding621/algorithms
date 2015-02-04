// https://oj.leetcode.com/problems/spiral-matrix-ii/

public class SpiralMatrixGenerate {
	
	public static int[][] generateMatrix(int n) {
		int[][] matrix = new int[n][n];
		fillMatrixRec(matrix, n, 1, 0);
		return matrix;
	}

	static void fillMatrixRec(int[][] matrix, int size, int start, int pos) {
		if (size == 0)
			return;

		int next = start;
		for (int i=0; i<size; i++) {
			matrix[pos][pos+i] = next++;
		}
		for (int i=1; i<size; i++) {
			matrix[pos+i][pos+size-1] = next++;
		}
		if (size > 1) {
			for (int i=size-2 ; i>=0 ;i--) {
				matrix[pos+size-1][pos+i] = next++;
			}
			for (int i=size-2 ; i>0 ; i--) {
				matrix[pos+i][pos] = next++;
			}
		}
		fillMatrixRec(matrix, size - 2, next, pos+1);
	}

}