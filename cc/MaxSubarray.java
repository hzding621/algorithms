// https://oj.leetcode.com/problems/maximum-subarray/

public class MaxSubarray {
	public static int maxSubArray(int[] A) {
        if (A.length == 0)
            return 0;
        int[] maxUntill = new int[A.length];
        maxUntill[0] = A[0];
        for (int i=1; i<A.length; i++) {
            maxUntill[i] = Math.max(A[i], A[i]+maxUntill[i-1]);
        }
        int max = Integer.MIN_VALUE;
        for (int i=0; i<A.length; i++)
            max = Math.max(max, maxUntill[i]);
        return max;
    }

    public static void main(String[] args) {
    	int[] array = new int[] {-2,1,-3,4,-1,2,1,-5,4};
    	System.out.println(maxSubArray(array));
    }
}