public class ListNode {
	ListNode next = null;
	int val;

	public ListNode(int d) {
		val = d;
	}

	public ListNode(int[] array) {
		val = array[0];
		ListNode next = this;
		int i = 1;
		while ( i < array.length) {
			next.next = new ListNode(array[i++]);
			next = next.next;
		} 

	}

	public void appendToTail(int d) {
		ListNode end = new ListNode(d);
		ListNode n = this;
		while (n.next != null)
			n = n.next;

		n.next = end;
	}

	public void print() {
		ListNode n = this;
		System.out.print("[" + n.val);

		n = n.next;
		while (n != null)
		{
			System.out.print(", " + n.val);
			n=n.next;
		}
		System.out.println("]");
	}
}