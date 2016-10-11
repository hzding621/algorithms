import java.util.*;

public class PartitionList {

	public static ListNode partition(ListNode head, int x) {
		ListNode small = null, smallTail = null, large = null, largeTail = null, next= null;
		while (head != null) {
			next = head.next;
			if (head.val < x) {
				if (small == null) {
					small = smallTail = head;	
				} else {
					smallTail.next = head;
					smallTail = smallTail.next;
				}
				smallTail.next = null;
			} else {
				if (large == null) {
					large = largeTail = head;
				} else {
					largeTail.next = head;
					largeTail = largeTail.next;
				}
				largeTail.next = null;
			 }
			head = next;
		}       
		if (small != null) {
			smallTail.next = large;
			return small;
		}
		else {
			return large;
		}
	}

	public static void main(String[] args) {
		ListNode l = new ListNode(new int[] {1,4,3,2,5,2});
		l = partition(l, 3);
		l.print();
	}
}
