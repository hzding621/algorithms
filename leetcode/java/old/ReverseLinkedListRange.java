import java.util.*;

public class ReverseLinkedListRange {

	public static ListNode reverseBetween(ListNode head, int m, int n) {

		if (head == null)
			return null;
		if (m == n)
			return head;

		boolean misone = m == 1;
		if (misone) {
			ListNode temp = new ListNode(0);
			temp.next = head;
			head = temp;
			m++;
			n++;
		}

		ListNode i = head;
		while (m > 2) {
			m--;
			n--;
			i = i.next;
		}
		ListNode t = i.next, tail = t;
		ListNode j = t.next, k = j;
		
		do {
			k = k.next;
			j.next = t;
			t = j;
			j = k;
		} while (--n > 2);
		
		tail.next = j;
		i.next = t;

		if (misone)
			return head.next;
		else
			return head;
	}

	public static void main(String[] args) {
		ListNode n = new ListNode(new int[] {1,2,3,4,5});
		n = reverseBetween(n,2,5);
		n.print();
	}
}