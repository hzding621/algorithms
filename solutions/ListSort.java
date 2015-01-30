public class ListSort {
	public static LinkedListNode mergeTwoLists(LinkedListNode l1, LinkedListNode l2) {
		if (l2 == null)
			return l1;
		else if (l1 == null)
			return l2;
		
		LinkedListNode head = null;
		LinkedListNode ret = null;
		if (l1.val <= l2.val) {
			ret = head = l1;
			l1 = l1.next;
		}
		else {
			ret = head = l2;
			l2 = l2.next;
		}
		while (l1 != null && l2 != null ) {
			if (l1.val <= l2.val) {
				head.next = l1;
				head = head.next;
				l1 = l1.next;
			} else {
				head.next = l2;
				head = head.next;
				l2 = l2.next;
			}
		}
		if (l1 != null) {
			while (l1 != null) {
				head.next = l1;
				head = head.next;
				l1 = l1.next;
			}
		} else {
			while (l2 != null) {
				head.next = l2;
				head = head.next;
				l2 = l2.next;
			}
		}
		return ret;
	}

	public static LinkedListNode sortList(LinkedListNode head) {
		if (head == null || head.next == null)
			return head;

		LinkedListNode ptr1 = head;
		LinkedListNode ptr2 = head;
		while (ptr2.next != null && ptr2.next.next != null) {
			ptr2 = ptr2.next.next;
			ptr1 = ptr1.next;
		}

		LinkedListNode left = head;
		LinkedListNode right = ptr1.next;
		ptr1.next = null;
		left = sortList(left);
		right = sortList(right);
		return mergeTwoLists(left, right);

	}


	public static void main(String[] args) {
		LinkedListNode list = new LinkedListNode(new int[] {2,5,3,4,1, 7, 3,1,0});
		list = sortList(list);
		list.print();
	}
	

}