public class ListCycle {

	public static ListNode detectCycle(ListNode head) {

        ListNode slow = head;
        ListNode fast = head;
        
        while (fast != null && slow != null) {
            slow = slow.next;
            fast = fast.next;
            if (fast != null) {
                fast = fast.next;
            }
            if (fast == slow)
                break;
        }
        
        if (fast == null) 
            return null;
        
        slow = head;
        while ( slow != fast) {
            slow = slow.next;
            fast = fast.next;
        }
        
        return fast;
    }


}