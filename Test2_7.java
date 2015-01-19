import java.util.*;

public class Test2_7 {
	public static boolean checkPalinRevAndComp(LinkedListNode head) {
		if (head == null)
			return true;

		LinkedListNode reversed = ListReverse.reverseSafe(head);
		while (head.next != null) {
			if (head.data != reversed.data)
				return false;
			head=head.next;
			reversed=reversed.next;
		}
		return true;
	}

	public static boolean checkPalinIter(LinkedListNode head) {
		if (head == null)
			return true;

		Deque<Integer> stack = new ArrayDeque<Integer>();

		LinkedListNode fast = head, slow = head;
		while (fast != null && fast.next != null) {
			stack.push(slow.data);
			slow = slow.next;
			fast = fast.next.next;
		}

		if (fast != null) {
			/* odd length */
			slow = slow.next;
		}

		while (slow != null) {
			if (slow.data != stack.pop())
				return false;
			slow=slow.next;
		}
		return true;
	}

	public static void main(String[] args) {
		int[][] testCases = {
			{1,2,3,4,5,4,3,2,1},
			{1,2,2,1},
			{1,2},
			{1,2,3},
			{2}
		};

		String[] solutions = {
			"true",
			"true",
			"false",
			"false",
			"true"
		};

		for (int i=0; i<testCases.length; i++) {
			LinkedListNode list = new LinkedListNode(testCases[i]);
			list.print();
			System.out.println("checkPalinRevAndComp(list): " + checkPalinRevAndComp(list));
			System.out.println("checkPalinIter(list): " + checkPalinIter(list));
			System.out.println(">>> Expected: " + solutions[i] + "\n");
		}
	}
}