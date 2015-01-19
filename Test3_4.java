import java.util.*;

public class Test3_4 {

	public static class Tower {
		Stack<Integer> stack;
		int index;
		public Tower(int d) {
			stack = new Stack<Integer>();
			index = d;
		}
		public int index() {
			return index;
		}

		public void add(int d) {
			if (!stack.isEmpty() && stack.peek() <= d)
				System.out.println("Error placing disk " + d);
			else
				stack.push(d);
		}

		public void moveTopTo(Tower t) {
			int top = stack.pop();
			t.add(top);
			System.out.println("Move disk " + top + " from " + index() + " to " + t.index());
		}

		public void moveDisks(int n, Tower dest, Tower buffer) {
			if (n > 0) {
				moveDisks(n-1, buffer, dest);
				moveTopTo(dest);
				buffer.moveDisks(n-1, dest, this);
			}
		}

	}

	public static void main(String []args) {
		Tower[] towers = new Tower[3];
		for (int i = 0; i < 3; i++)
			towers[i] = new Tower(i);
		int N = 3;
		for (int i = 0; i < N; i++)
			towers[0].add(N-i);
		towers[0].moveDisks(N, towers[2], towers[1]);

	}
}