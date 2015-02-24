import java.util.*;

public class ListRemoveDuplicate {

public static ListNode removeDup(ListNode list) {
	HashSet<Integer> set = new HashSet<Integer>();
    ListNode head = list;
    ListNode cur = list;
    ListNode next = list.next;
    while (cur != null) {
        set.add(cur.val);
        while (next != null && set.contains(next.val)) {
            next=next.next;
        }
        cur.next=next;
        cur=cur.next;
    }
    return head;
}

public static void main(String[] args) {
	ListNode n = new ListNode(new int[] {1,2,3,3,4});
	n = removeDup(n);
	n.print();
}

}