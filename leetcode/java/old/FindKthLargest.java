import java.util.*;

public class FindKthLargest {

	public static int findKthLargest(int[] nums, int k) {
		PriorityQueue<Integer> pq = new PriorityQueue<Integer>();
		for (int i : nums) {
			if (pq.size() == k) {
				if (i > pq.peek()) {
					pq.remove();
					pq.add(i);
				}
			} else {	
				pq.add(i);
			}
		}
		return pq.peek();
	}

	public static void main(String[] args) {
		int n = findKthLargest(new int[]{3,2,1,5,6,4}, 3);
		System.out.println(n);
	}
}