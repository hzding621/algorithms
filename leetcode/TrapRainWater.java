import java.util.*;

public class TrapRainWater {

	public static int trap(int[] A) {
		if (A.length == 0)
			return 0;
			
		int[] maxLeft = new int[A.length];
		int[] maxRight = new int[A.length];

		int total = 0;

		maxLeft[0] = 0;
		maxRight[A.length-1] = A.length-1;
		for (int i=1; i<A.length; i++) {
			maxLeft[i] = A[maxLeft[i-1]] > A[i] ? maxLeft[i-1] : i;
			maxRight[A.length-1-i] = A[maxRight[A.length-i]] > A[A.length-1-i] ? maxRight[A.length-i] : A.length-1-i;
		}

		for (int i=0; i<A.length; i++) {
			int min = Math.min(A[maxRight[i]], A[maxLeft[i]]);
			total += min >= A[i] ? (min-A[i]) : 0;
		}
		return total;

	}

	public static void main(String[] args) {
		int[][] testCases = new int[][] {

			{0,1,0,2,1,0,1,3,2,1,2,1},
			{0,2,1,1,2,1,0,1,3,2,1,2,3},
			{1,0,0,0,1},
			{2,0,0,3}
			};
		for (int i=0; i<testCases.length; i++)
			System.out.println(trap(testCases[i]));
 	}
}