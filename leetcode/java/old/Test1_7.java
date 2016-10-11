import java.util.*;

public class Test1_7 {
	public void setZero(int[][] matrix) {
		int m = matrix.length;
		int n = matrix[0].length;

		BitSet row = new BitSet(m);
		BitSet column = new BitSet(n);
		for (int i=0; i < m; i++) {
			for (int j=0; j < n; j++) {
				if (matrix[i][j] == 0) {
					row.set(i, true);
					column.set(j, true);
				}
			}
		}

		for (int i=0; i < m; i++) {
			for (int j=0; j < n; j++) {
				if (row.get(i) == true || column.get(j) == true)
					matrix[i][j] = 0;
			}
		}
	}

	public static void main(String[] args) {

	}
}