public class Test2_5 {
	
	public static LinkedListNode listSum(LinkedListNode x, LinkedListNode y) {
		
		int leftover=0;
		LinkedListNode lst = null;
		LinkedListNode ret = null;
		while (x != null && y != null) {
			int xval = x.data;
			int yval = y.data;
			int sum = xval + yval + leftover;
			if (sum >= 10) {
				leftover=1;
				sum=sum-10;
			}
			else {
				leftover=0;
			}
			if (lst == null) {
				lst = new LinkedListNode(sum);
				ret = lst;
			}
			else {
				lst.next=new LinkedListNode(sum);
				lst=lst.next;
			}
			x=x.next;
			y=y.next;
		}
		if (x != null) {
			if (leftover != 0) {
				x.data=x.data+leftover;
				leftover=0;
			}
			lst.next=x;
		}
		else if (y != null) {
			if (leftover != 0) {
				y.data=y.data+leftover;
				leftover=0;
			}
			lst.next=y;
		}
		else {
			if (leftover != 0)
				lst.next = new LinkedListNode(leftover);
		}
		return ret;
	}

	public static void main(String []args) {
		int[] a = new int[] {1,1};
		int[] b = new int[] {9,8,1};
		LinkedListNode x = new LinkedListNode(a[0]);
		for (int i = 1; i < a.length; i++)
			x.appendToTail(a[i]);
		LinkedListNode y = new LinkedListNode(b[0]);
		for (int i = 1; i < b.length; i++)
			y.appendToTail(b[i]);

		x.print();
		y.print();
		System.out.println("Sum = "); 
		listSum(x,y).print();

	}
}