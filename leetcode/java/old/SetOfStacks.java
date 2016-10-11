import java.util.*;

public class SetOfStacks<E> {
	ArrayList<Stack<E>> stacks;
	int size;
	int capacity;
	int numStack;

	public SetOfStacks(int capacity) {
		this.stacks = new ArrayList<Stack<E>>();
		this.size=0;
		this.numStack=0;
		this.capacity=capacity;
	}

	public E push(E item) {
		if (size % capacity == 0) {
			Stack<E> newStack = new Stack<E>();
			newStack.push(item);
			stacks.add(newStack);
			numStack++;
		}
		else {
			stacks.get(numStack-1).push(item);
		}
		size++;
		return item;
	}

	public E pop() {
		if (size == 0)
			return null;
		E item = stacks.get(numStack-1).pop();
		if (size % capacity == 1) {
			stacks.remove(numStack-1);
			numStack--;
		}
		size--;
		return item;
	}

	public E peek() {
		if (size == 0)
			return null;
		return stacks.get(numStack-1).peek();
	}

	// public E popAt(int index) {};


}