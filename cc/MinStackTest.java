// https://oj.leetcode.com/problems/min-stack/

import java.util.*;

class MinStack {

	Stack<Integer> stack = new Stack<Integer>();
    Stack<Integer> min = new Stack<Integer>();
    
    public void push(int x) {
        stack.push(x);
        if (min.empty() || x <= min.peek())
            min.push(x);
    }

    public void pop() {
        if (min.peek().equals(stack.peek()))
            min.pop();
        stack.pop();
    }

    public int top() {
        return stack.peek();
    }

    public int getMin() {
        return min.peek();
    }

}

public class MinStackTest {
	public static void main(String[] args) {
		MinStack stack = new MinStack();
		stack.push(512);
		stack.push(-1024);
		stack.push(-1024);
		stack.push(512);
		stack.pop();
		System.out.println(stack.getMin());
		stack.pop();
		System.out.println(stack.getMin());
		stack.pop();
		System.out.println(stack.getMin());

	}
}