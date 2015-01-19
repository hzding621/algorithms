import java.util.*;

public class MinStack<E extends Comparable<E>> extends Stack<E> { 
	Stack<E> min;

	public MinStack() {
		min = new Stack<E>();
	}

	public E push(E item) {

		if (min.empty() || item.compareTo(min.peek()) <= 0) {
			min.push(item);
		}
		super.push(item);

		return item;
	}

	public E pop() {
		E item = super.pop();
		if (item.compareTo(min.peek()) == 0)
			min.pop();
		return item;
	}

	public E min() {
		return min.peek();
	}
}