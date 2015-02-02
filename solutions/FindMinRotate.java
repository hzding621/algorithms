// https://oj.leetcode.com/problems/find-minimum-in-rotated-sorted-array/

public class FindMinRotate {

	public static int findMin(int[] num, int begin, int end) {
		
		if (begin == end)
			return num[begin];
		if (begin + 1 == end)
			return Math.min(num[begin], num[end]);
		
		int mid = (begin+end)/2;
		int midVal = num[mid];
		if (num[begin] < midVal && midVal < num[end])
			return num[begin];
			
		if (num[begin] < midVal && num[end] < midVal) {
			return findMin(num, mid+1, end);
		}
		
		return findMin(num, begin, mid);
	}
	
	public static int findMin(int[] num) {
		if (num.length == 1)
			return num[0];
		return findMin(num, 0, num.length-1);
	}

	public static void main(String[] args) {

		System.out.println(findMin(new int[] {6,7,8,1,2,3,4,5}));

	}

}