public class AddTwoNumbers {

	public static ListNode addTwoNumbers(ListNode l1, ListNode l2) {

		if (l1 == null) {
			return l2;
		} else if (l2 == null) {
			return l1;
		}

		int nextval = l1.val + l2.val;
		int carry = 0;
		if (nextval >= 10) {
			nextval -= 10;
			carry = 1;
		}

		ListNode head = new ListNode(nextval);
		ListNode next = head;

		while (l1.next != null && l2.next != null) {
			l1 = l1.next; l2 = l2.next;
			nextval = l1.val + l2.val + carry;
			if (nextval >= 10) {
				nextval -= 10;
				carry = 1;
			} else {
				carry = 0;
			}
			next.next = new ListNode(nextval);
			next = next.next;
		}

		if (l1.next != null) {
			while (l1.next != null) {
				l1=l1.next;
				nextval = l1.val + carry;
				if (nextval >= 10) {
					nextval -= 10;
					carry = 1;
				} else {
					carry = 0;
				}
				next.next = new ListNode(nextval);
				next = next.next;
			}
		} else {
			while (l2.next != null) {
				l2=l2.next;
				nextval = l2.val + carry;
				if (nextval >= 10) {
					nextval -= 10;
					carry = 1;
				} else {
					carry = 0;
				}
				next.next = new ListNode(nextval);
				next = next.next;
			}
		}

		if (carry == 1) {
			next.next = new ListNode(carry);
		}
		return head;

	}

	public static void main(String[] args) {
		ListNode a = new ListNode(new int[] {5});
		ListNode b = new ListNode(new int[] {5});
		addTwoNumbers(a,b).print();
	}


}
