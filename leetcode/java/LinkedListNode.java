public class LinkedListNode {
	LinkedListNode next = null;
	int val;

	public LinkedListNode(int d) {
		val = d;
	}

	public LinkedListNode(int[] array) {
		val = array[0];
		for (int i = 1; i < array.length; i++)
			appendToTail(array[i]);
	}

	public void appendToTail(int d) {
		LinkedListNode end = new LinkedListNode(d);
		LinkedListNode n = this;
		while (n.next != null)
			n = n.next;

		n.next = end;
	}

	public void print() {
		LinkedListNode n = this;
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