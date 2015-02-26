import java.util.*;

public class Helpers {

	public static void print(int[] array) {
		System.out.println(Arrays.toString(array));
	}
	public static void print(int[][] matrix) {
		for (int i=0; i<matrix.length; i++) {
			print(matrix[i]);
		}
		System.out.println();
	}

	public static void print(boolean[] array) {
		System.out.println(Arrays.toString(array));
		// for (int i=0; i<array.length; i++)
		// 	System.out.print(array[i] ? 1 : 0);
		// System.out.println();
	}

	public static void print(boolean[][] matrix) {
		for (int i=0; i<matrix.length; i++) {
			print(matrix[i]);
		}
		System.out.println();
	}

	public static void print(char[] array) {
		System.out.println(Arrays.toString(array));
	}
	public static void print(char[][] matrix) {
		for (int i=0; i<matrix.length; i++) {
			print(matrix[i]);
		}
		System.out.println();
	}

	public static void print(int[] array, int length) {
		if (length > array.length)
			print(array);
		System.out.println(Arrays.toString(Arrays.copyOfRange(array, 0, length)));
	}

}

