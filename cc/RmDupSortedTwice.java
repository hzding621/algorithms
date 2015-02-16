// https://oj.leetcode.com/problems/remove-duplicates-from-sorted-array-ii/

public class RmDupSortedTwice {
	
	public static int removeDuplicates(int[] A) {

		if (A.length <= 2)
			return A.length;

		int i=1, j=1;
		int temp = A[0];
		int count = 1;
		while (j<A.length) {
			if (A[j] == temp) {
				if (count == 1) {
					A[i++] = A[j];
				} 
				count++;
			} else {
				count = 1;
				temp = A[j];
				A[i++] = A[j];
			}
			j++;
		}

		return i;
	}

	public static void main(String[] args) {
		int[] array = new int[] {1,1,1,1,1,2,2,2,2,3,3,4};
		int length = removeDuplicates(array);
		System.out.println(length);	
		Helpers.print(array, length);
	}
}