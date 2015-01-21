// https://oj.leetcode.com/problems/merge-sorted-array/

public class MergeInPlace {
	public static void merge(int A[], int m, int B[], int n) {
		int tailA = m-1;
		int tailB = n-1;
		int tailMerge = m+n-1;
		while (tailA >= 0 && tailB >= 0) {
			if (A[tailA] > B[tailB]) {
				A[tailMerge] = A[tailA];
				tailA--;
			} else {
				A[tailMerge] = B[tailB];
				tailB--;
			}
			tailMerge--;
		}
		while (tailB >= 0) {
			A[tailMerge--] = B[tailB--];
		}
	}

	public static void main(String[] args) {

	}
}