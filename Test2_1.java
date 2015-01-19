import java.util.*;

public class Test2_1 {

	public static void removeDuplicate(LinkedListNode head) {
		HashSet<Integer> table = new HashSet<Integer>();
		LinkedListNode prev = null;
		while (head != null)
		{
			if (table.contains(head.data))
			{
				prev.next = head.next;
			}
			else
			{
				table.add(head.data);
				prev = head;
			}
			head = head.next;
		}
	}

	public static void main(String []args) {
		int[] array = new int[] {1, 2, 5, 3, 5, 1, 2, 3, 4};
		LinkedListNode list = new LinkedListNode(array[0]);
		for (int i = 1; i < array.length; i++)
			list.appendToTail(array[i]);

		list.print();
		removeDuplicate(list);
		list.print();

	}

}