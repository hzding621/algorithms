// https://oj.leetcode.com/problems/swap-nodes-in-pairs/

public class ListSwapPairs {
	public static ListNode swapPairs(ListNode head) {
		if (head == null || head.next == null)
			return head;
		ListNode rest = head.next.next;
		head.next.next = head;
		head = head.next;
		head.next.next = swapPairs(rest);
		return head; 
	}

	public static void main(String[] args) {
		ListNode lists = new ListNode(new int[] {1,2,3,4,5});
		lists = swapPairs(lists);
		lists.print();
	}
}