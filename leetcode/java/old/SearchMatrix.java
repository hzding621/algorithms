// https://oj.leetcode.com/problems/search-a-2d-matrix/

public class SearchMatrix {

	static class Result {
		boolean found = false;
		int index;
	}

	public static Result firstStep(int[][] matrix, int target, int start, int end) {

		Result r = new Result();

		if (start == end ) {
			if (matrix[start][0] == target) {
				r.found = true;
				r.index = start;
				return r;
			} else {
				r.index = start;
				return r;
			}
		}

		if (start + 1 == end) {
			if (matrix[start][0] == target) {
				r.found = true;
				r.index = start;
			} else if (matrix[end][0] == target){
				r.found = true;
				r.index = end;
			} else if (target > matrix[end][0]) {
				r.index = end;
			} else {
				r.index = start;
			}
			return r;
		}

		int mid = (start + end) / 2;
		if (matrix[mid][0] == target) {
			r.found = true;
			r.index = mid;
			return r;
		} else if (matrix[mid][0] < target) {
			return firstStep(matrix, target, mid, end);
		}  else 
			return firstStep(matrix, target, start, mid);

	}

	public static boolean secondStep(int[] array, int target, int start, int end) {
		if (start > end ) 
			return false;
		if (start == end) {
			return array[start] == target;
		}
		int mid = (start + end) / 2;
		if (array[mid] == target)
			return true;
		else if (array[mid] < target)
			return secondStep(array, target, mid+1, end);
		else 
			return secondStep(array, target, start, mid-1);
	}

	public static boolean searchMatrix(int[][] matrix, int target) {

		if (matrix.length == 0 || matrix[0].length == 0)
			return false;

		Result r = firstStep(matrix, target, 0, matrix.length-1);
		if (r.found == true)
			return true;
		else {
			int[] array = matrix[r.index];
			return secondStep(array, target, 0, array.length-1);
		}
	}

	public static void main(String[] args) {
		int[][] matrix = new int[][] {
			{1,3,5,7},
			{10,11,16,20},
			{23,30,34,50},
			{51,52,53,54}
		};
		System.out.println(searchMatrix(matrix, 23));
	}



}