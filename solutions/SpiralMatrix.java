// https://oj.leetcode.com/problems/spiral-matrix/

import java.util.*;

public class SpiralMatrix {
	public static List<Integer> spiralOrder(int[][] matrix) {
		List<Integer> elems = new ArrayList<Integer>();
		if (matrix.length == 0 || matrix[0].length == 0)
			return elems;

		spiralOrderRec(matrix, 0, 0, matrix[0].length, matrix.length, elems);
		return elems;
	}

	public static void spiralOrderRec(int[][] matrix, int startX, int startY, 
								int width, int height, List<Integer> elems) {
		
		System.out.println(startX + ", " + startY + ", " + width + ", " + height);

		if (width <= 0 || height <= 0)
			return;

		for (int i=0; i<width; i++) {
			elems.add(matrix[startY][i+startX]);
		}
		for (int j=1; j<height; j++) {
			elems.add(matrix[startY+j][width-1+startX]);
		}

		if (height > 1) {
			for (int i=width-2; i>=0; i--) {
				// System.out.println(matrix[startY+height-1][i+startX]);
				elems.add(matrix[startY+height-1][i+startX]);
			}
		}
		
		if (width > 1 ) {
			for (int j=height-2; j>0; j--) {
				elems.add(matrix[startY+j][startX]);
			}
		}
		

		spiralOrderRec(matrix, startX+1, startY+1, width-2, height-2, elems);

	}

	public static void main(String[] args) {
		int [][]matrix = {
			{ 1, 2, 3, 4},
			{ 5, 6, 7, 8},
			{ 9, 10, 11, 12},
			{13, 14, 15, 16},
			{17, 18, 19, 20}
		};
		List<Integer> elems = spiralOrder(matrix);

		for (int elem : elems) {
			System.out.print(elem + ", ");
		}
	}
}