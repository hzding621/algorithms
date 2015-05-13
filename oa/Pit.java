import java.util.*;

public class Pit {

	static int find_top(int[] A, int i) {
        while (i < A.length-1 && A[i] < A[i+1]) {
            i++;
        }
        return i;
    }
    
    static int find_bottom(int[] A, int i) {
        while (i < A.length-1 && A[i] > A[i+1]) {
            i++;   
        }
        return i;
    }
    
    static int search(int[] A, int i) {
        while (i < A.length - 1 && A[i] <= A[i+1]) {
            i++;
        }
        return i;
    }
    
    public static int solution(int[] A) {
        // write your code in Java SE 8
        int n = A.length;
        if (n < 3)
            return -1;
        int i = search(A, 0);
        int max = -1, min = 0, m1 = 0, m2 = 0, j = i;
        while (i != n-1) {
            j = find_bottom(A, i);    
            m1 = A[i] - A[j];
            i = find_top(A, j);
            if (i != j) {
                m2 = A[i] - A[j];
                min = Math.min(m1, m2);
                max = Math.max(max, min);
            }
            i = search(A, i);
        }
        return max;
    }


	public static void main(String[] args) {
		int[] input = {0,-1,-2,-3,-4,5};
		System.out.println(solution(input));
	}
}