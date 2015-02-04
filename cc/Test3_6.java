import java.util.*;

public class Test3_6 {
	public static void stackSort(Stack<Integer> s) {
		Stack<Integer> helper = new Stack<Integer>();
		while (!s.empty()) {
			int tmp = s.pop();
			while (!helper.empty() && helper.peek() > tmp) {
				s.push(helper.pop());
			}
			helper.push(tmp);
		}
		while (!helper.empty())
			s.push(helper.pop());
	}

	public static void main(String[] args) {
		Stack<Integer> s = new Stack<Integer>();
		int[] testCase = new int[] {8,4,2,3,5,6,1,7,0,9};
		for (int i=0; i < testCase.length; i++)
			s.push(testCase[i]);
		stackSort(s);
		while (!s.empty())
			System.out.print(s.pop() + ", ");
		System.out.println();
	}
}