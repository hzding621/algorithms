import java.util.*;

public class Test3_2 {
	
	/* major code in MinStack.java */

	public static void main(String[] args) {
		MinStack<Integer> test = new MinStack<Integer>();
		int[] testCase = new int[] {3,2,1,2,3};
		System.out.println(Arrays.toString(testCase));
		for (int i=0; i < testCase.length; i++) {
			test.push(testCase[i]);
			System.out.print(test.min() + ", ");
		}

	}

}