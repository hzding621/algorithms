public class SortedListToBST {

	public static TreeNode sortedListToBST(ListNode head) {
        
		if (head == null)
			return null;
		if (head.next == null)
			return new TreeNode(head.val);
		if (head.next.next == null) {
			TreeNode n = new TreeNode(head.val);
			n.right = new TreeNode(head.next.val);
			return n;
		}

		// find middle node and serve as root
		ListNode n1 = head, n2 = head;
		ListNode prev = null;
		while (n1.next != null && n1.next.next != null) {
			n1 = n1.next.next;
			prev = n2;
			n2 = n2.next;
		}
		TreeNode root = new TreeNode(n2.val);
		prev.next = null;
		root.left = sortedListToBST(head);
		root.right = sortedListToBST(n2.next);
		return root;
    }

	public static void main(String[] args) {
		ListNode list = new ListNode(new int[] {1,3});
		TreeNode tree = sortedListToBST(list);
		tree.print();
	}
}