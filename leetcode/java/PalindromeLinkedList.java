public class PalindromeLinkedList {

    public static int getLength(ListNode n) {
        int len = 0;
        while (n != null) {
            n = n.next;
            len++;
        }
        return len;
    }
    public static ListNode reverse(ListNode head) {
        ListNode t = null, n = head, t2 = n.next;
        while (t2 != null) {
            t = n;
            n = t2;
            t2 = t2.next;
            n.next = t;
        }
        head.next = null;
        return n;
    }

    public static boolean isPalindrome(ListNode head) {
        if (head == null)
            return true;
        int length = getLength(head);
        int half = length/2;
        ListNode n = head;
        while (half > 0) {
            n = n.next;
            half--;
        }
        ListNode tail = reverse(n);
        half = length/2;
        boolean res = true;
        ListNode t = tail;
        n = head;
        while (half > 0) {
            if (t.val != n.val) {
                res = false;
                break;
            }
            t = t.next;
            n = n.next;
            half--;
        }
        reverse(tail);
        return res;
    }

    public static void main(String[] args) {
        ListNode n = new ListNode(new int[] {1,1,2,1});
        System.out.println(isPalindrome(n));
        n.print();
    }
}
