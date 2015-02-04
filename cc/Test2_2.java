import java.util.*;

public class Test2_2 {

	public static class IntWrapper {
		public int value = 0;
	}

	public static LinkedListNode findLastAt(LinkedListNode head, int i) {
		if (head == null)
			return null;

		LinkedListNode n = head;
		int len = 1;
		while (n.next != null)
		{
			n=n.next;
			len++;
		}

		if (len - i < 0)
			return null;
		int offset = len-i;
		while (offset>0)
		{
			head = head.next;
			offset--;
		}
		return head;
	}

	public static LinkedListNode findLastAtIter(LinkedListNode head, int k) {
		LinkedListNode p1 = head;
		for (int i = k; i > 1; i--) {
			if (p1.next != null)
				p1=p1.next;
			else
				return null;
		}

		LinkedListNode p2 = head;
		while (p1.next != null) {
			p1=p1.next;
			p2=p2.next;
		}
		return p2;
	}

	public static LinkedListNode findLastAtRec(LinkedListNode head, int k) {
		IntWrapper i = new IntWrapper();
		return findLastAtRecHelper(head, k, i);
	}

	public static LinkedListNode findLastAtRecHelper(LinkedListNode head, int k, IntWrapper i) {
		if (head == null)
			return null;

		LinkedListNode node = findLastAtRecHelper(head.next, k, i);
		i.value = i.value + 1;
		if (i.value == k)
			return head;
		return node;
	}

	public static void main(String []args) {
		int[] array = new int[] {1, 2, 5, 3, 5, 1, 2, 3, 4};
		LinkedListNode list = new LinkedListNode(array[0]);
		for (int i = 1; i < array.length; i++)
			list.appendToTail(array[i]);

		list.print();
		
		System.out.println("findLastAt(2): " + findLastAtIter(list, 2).data);
		System.out.println("findLastAt(4): " + findLastAtIter(list, 4).data);
		System.out.println("findLastAt(8): " + findLastAtIter(list, 8).data);
		System.out.println("findLastAt(16): " + findLastAtIter(list, 16));

	}

}