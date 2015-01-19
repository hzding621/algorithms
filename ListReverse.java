public class ListReverse {
	public static LinkedListNode reverseSafe(LinkedListNode head) {
		if (head == null)
			return null;
		LinkedListNode newHead =  new LinkedListNode(head.data);
		LinkedListNode next = newHead;
		while (head.next != null) {
			head=head.next;
			newHead = new LinkedListNode(head.data);
			newHead.next = next;
			next = newHead;
		}
		return newHead;


	}

	public static void main(String []args) {
		int[] array = new int[] {1,2,3,4,5,6,7,8,9,10};
		LinkedListNode list = new LinkedListNode(array[0]);
		for (int i = 1; i < array.length; i++)
			list.appendToTail(array[i]);

		list.print();
		LinkedListNode newList = reverseSafe(list);
		newList.print();

	}

}