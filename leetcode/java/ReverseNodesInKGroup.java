public class ReverseNodesInKGroup {

	public static ListNode reverseKGroup(ListNode head, int k) {
		if (k == 1)
			return head;

		int k2 = k, k3 = k;
		ListNode t = head;
		while (k2-- > 0) {
			if ( t == null)
				return head;
			t = t.next;
		} // make sure length is at least k

		t = null;
		ListNode p1 = head, p2 = head;
		while (k3-- > 0) {
			p2 = p2.next;
			p1.next = t;
			t = p1;
			p1 = p2;
		}
		head.next = reverseKGroup(p1, k);
		return t;
	}

	public static void main(String[] args) {
		ListNode n = new ListNode(new int[] {1,2,3,4,5,6});
		n = reverseKGroup(n, 3);
		n.print();
	}
}