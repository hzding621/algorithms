import java.util.*;

public class RotateImage {

	static void rotateRec(int[][] matrix, int x, int y, int size) {

		if (size <= 0)
			return;
		int[] firstRow = new int[size];
		for (int i=0; i<size; i++)
			firstRow[i] = matrix[x][y+i];

		for (int i=0; i<size; i++)
			matrix[x][y+size-1-i] = matrix[x+i][y];
		
		for (int i=1; i<size; i++)
			matrix[x+i][y] = matrix[x+size-1][y+i];
		for (int i=1; i<size; i++)
			matrix[x+size-1][y+i] = matrix[x+size-1-i][y+size-1];
		for (int i=0; i<size-1; i++)
			matrix[x+size-1-i][y+size-1] = firstRow[size-1-i];

		rotateRec(matrix, x+1, y+1, size-2);

	}

	public static void rotate(int[][] matrix) {
		if (matrix.length == 0 || matrix[0].length == 0)
			return;
		rotateRec(matrix, 0, 0, matrix.length);
	}

	public static void main(String[] args) {
		int[][] matrix = {
			{1,2,3,4},
			{5,6,7,8},
			{9,10,11,12},
			{13,14,15,16}
		};
		rotate(matrix);
		Helpers.print(matrix);
	}
}