public class LinkedListNode {
	LinkedListNode next = null;
	int data;

	public LinkedListNode(int d) {
		data = d;
	}

	public LinkedListNode(int[] array) {
		data = array[0];
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
		System.out.print("[");
		while (n != null)
		{
			System.out.print(n.data + ", ");
			n=n.next;
		}
		System.out.println("]");
	}
}