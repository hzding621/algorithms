import java.util.*;

public class Main {

	public int equilibrium(int[] A) {
		// write your code in Java SE 8
		int n = A.length; 
		if (n==0)
			return -1;
		else if (n==1)
			return 0;
		long[] from_start = new long[n];
		long[] from_end = new long[n];
		from_start[0] = A[0];
		for (int i = 1; i < n; i++) {
			from_start[i] = from_start[i-1] + A[i];
		}
		from_end[n-1] = A[n-1];
		for (int i = n-2; i>=0; i--) {
			from_end[i] = from_end[i+1] + A[i];   
		}
		if (from_end[1] == 0)
			return 0;
		else if (from_start[n-2] == 0)
			return n-1;
		for (int i=1; i<n-1; i++) {
			if (from_start[i-1] == from_end[i+1])
				return i;
		}
		return -1;
	}

	public static void main(String[] args) {
		
	}
}