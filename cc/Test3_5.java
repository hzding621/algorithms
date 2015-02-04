public class Test3_5 {
	public static void main(String[] args) {
		/* main code in MyQueue.java */

		MyQueue<Integer> queue = new MyQueue<Integer>();
		for (int i = 0; i < 10; i++) 
			queue.add(i);
		for (int i = 0; i < 10; i++)
			System.out.print(queue.remove() + ", ");
		System.out.println();
	}
}