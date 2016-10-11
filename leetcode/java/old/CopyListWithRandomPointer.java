public class CopyListWithRandomPointer {

	class RandomListNode {
		int label;
		RandomListNode next, random;
		RandomListNode(int x) { this.label = x; }
	}

	public static RandomListNode copyRandomList(RandomListNode head) {
		HashMap<RandomListNode, RandomListNode> mapping = new HashMap<RandomListNode, RandomListNode>();
		RandomListNode t = head;
		RandomListNode copyHead = null, tail = null;
		while (t != null) {
			if (copyHead == null) {
				copyHead = new RandomListNode(t.label);
				tail = copyHead;
			} else {
				tail.next = new RandomListNode(t.label);
				tail = tail.next;
			}
			mapping.put(t, tail);
			t = t.next;
		}

		// copy the random pointers
		t = head;
		RandomListNode t2 = copyHead;
		while (t != null) {
			t2.random = mapping.get(t.random);
			t = t.next;
			t2 = t2.next;
		}
		return copyHead;
	}

	public static void main(String[] args) {
		
	}
}