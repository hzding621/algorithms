public class ListInsertionSort {

	public static void swapTwoNode(LinkedListNode a, LinkedListNode b) {
		int temp = a.val;
		a.val = b.val;
		b.val = temp;
	}

	public static LinkedListNode insertionSortList(LinkedListNode head) {
		if (head == null)
			return head;
		insertionSortList(head.next);
		LinkedListNode node = head;
		while (node.next != null && node.val > node.next.val) {
			swapTwoNode(node, node.next);
			node = node.next;
		}
		return head;
	}

	public static void main(String[] args) {
		LinkedListNode list = new LinkedListNode(new int[] {4,5,2,7,1,3,0});
		insertionSortList(list).print();
	}
}