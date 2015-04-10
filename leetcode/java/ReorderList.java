// https://oj.leetcode.com/problems/reorder-list/

public class ReorderList {

	static void interleave(ListNode first, ListNode second) {

		while (first != null && second != null) {

			ListNode temp = first.next;
			ListNode temp2 = second.next;
			first.next = second;
			second.next = temp;

			first = temp;
			second = temp2;
		}


	}

	static ListNode reverse(ListNode head) {
		
		ListNode origin = head;
		ListNode temp = head.next;
		while (temp != null) {
			ListNode temp2 = temp.next;
			temp.next = head;
			head = temp;
			temp = temp2;
		}
		origin.next = null;
		return head;

	}

	public static void reorderList(ListNode head) {
		if (head == null || head.next == null)
			return;

		ListNode ptr1 = head;
		ListNode ptr2 = head;
		while (ptr2.next != null && ptr2.next.next != null) {
			ptr2 = ptr2.next.next;
			ptr1 = ptr1.next;
		}

		// starting from ptr1.next
		ListNode node = ptr1.next;
		ptr1.next = null;
		node = reverse(node);
		interleave(head, node);

	}

	public static void main(String[] args) {
		ListNode list = new ListNode(new int[] {1,2,3,4,5});
		reorderList(list);
		list.print();
	}


}