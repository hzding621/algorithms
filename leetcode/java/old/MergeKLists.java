import java.util.*;

class ListNodeComparator implements Comparator<ListNodeMarker> {
	public int compare(ListNodeMarker a, ListNodeMarker b) {
		return Integer.compare(a.n.val, b.n.val);
	}
	
} 

class ListNodeMarker {
	public ListNode n;
	public int index;
	public ListNodeMarker(ListNode n, int index) {
		this.n = n;
		this.index = index;
	}
}

public class MergeKLists {

	public static ListNode mergeKLists(List<ListNode> lists) {
		if (lists.isEmpty())
            return null;
        
		int k = lists.size();
		PriorityQueue<ListNodeMarker> pq = new PriorityQueue<ListNodeMarker>(k, new ListNodeComparator());
		ListNode cur = null, ret = null;
		for (int i=0; i<lists.size(); i++) {
		    if (lists.get(i) != null)
			    pq.add(new ListNodeMarker(lists.get(i), i));
		}
		while (!pq.isEmpty()) {
			ListNodeMarker n = pq.poll();
			int from = n.index;
			ListNode next = lists.get(from).next;
			if (next != null) {
				pq.add(new ListNodeMarker(next, from));
				lists.set(from, next);
			}
			if (cur == null) {
				cur = n.n;
				ret = n.n;
			} else {
				cur.next = n.n;
				cur = n.n;
			}
		}
		if (cur != null)
		    cur.next = null;
		return ret;
	}


	public static void main(String[] args) {
		List<ListNode> l = new ArrayList<ListNode>();
		l.add(new ListNode(new int[] {1,3,4,7,9}));
		l.add(new ListNode(new int[] {2,5,8,10,11}));
		l.add(new ListNode(new int[] {6,12}));
		ListNode sorted = mergeKLists(l);
		sorted.print();
	}
}