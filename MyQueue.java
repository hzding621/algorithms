import java.util.*;

public class MyQueue<E> {
	Stack<E> outStack, inStack;

	public MyQueue() {
		outStack = new Stack<E>();
		inStack = new Stack<E>();
	}

	public E add(E item) {
		return inStack.push(item);
	}

	public E remove() {
		checkShift();
		return outStack.pop();
	}

	public E peek() {
		checkShift();
		return outStack.peek();
	}

	public int size(){
		return inStack.size() + outStack.size();
	}

	void checkShift() {
		if (outStack.empty()) {
			while (inStack.empty() == false) {
				outStack.push(inStack.pop());
			}
		}
	}

}