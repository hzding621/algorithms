import java.util.*;

public class RemoveDuplicatesFromSortedListII {


	public static ListNode deleteDuplicates(ListNode head) {

		HashSet<Integer> hash = new HashSet<Integer>();
		HashSet<Integer> dup = new HashSet<Integer>();
		ListNode t = head;
		while (t != null) {
			if (hash.contains(t.val)) {
				dup.add(t.val);
			} else {
				hash.add(t.val);
			}
			t = t.next;
		}
		t = head;
		ListNode newHead = null, tail  = null;
		while (t != null && dup.contains(t.val)) {
			t = t.next;
		}
		tail = newHead = t;
		if (t != null) {
			t = t.next;
			while (t != null) {
				if (!dup.contains(t.val)) {
					tail.next = t;
					tail = t;
				}
				t = t.next;
			}
			tail.next = null;
		}
		return newHead;
	}

	public static void main(String[] args) {
		ListNode n = new ListNode(new int[] {1,1});
		n = deleteDuplicates(n);
		n.print();
	}
}