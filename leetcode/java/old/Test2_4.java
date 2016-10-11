import java.util.*;

public class Test2_4 {

	public static LinkedListNode partition(LinkedListNode head, int x) {
		
		LinkedListNode smaller = null;
		LinkedListNode larger = null;

		while (head != null)
		{
			LinkedListNode next = head.next;
			if (head.data < x)
			{
				head.next = smaller;
				smaller = head;
			}
			else
			{
				head.next = larger;
				larger = head;
			}
			head = next;
		}

		// concatenate two lists
		return concatenateList(smaller, larger);

	}

	public static LinkedListNode concatenateList(LinkedListNode a, LinkedListNode b) {
		if (a == null)
			return b;
		else {
			LinkedListNode n = a;
			while (n.next != null)
				n=n.next;
			n.next = b;
			return a;
		}
	}

	public static void main(String []args) {
		int[] array = new int[] {5,4,3,2,1,3,4,2,3,4,5};
		LinkedListNode list = new LinkedListNode(array[0]);
		for (int i = 1; i < array.length; i++)
			list.appendToTail(array[i]);

		list.print();
		LinkedListNode newList = partition(list, 3);
		newList.print();

	}

}