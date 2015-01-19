public class Test3_3 {
	public static void main(String[] args) {
		/* main code in SetofStacks */
		SetOfStacks<Integer> stacks = new SetOfStacks<Integer>(3);
		for (int i=0; i < 10; i++)
			stacks.push(i);
		for (int i=0; i < 10; i++)
			System.out.print(stacks.pop() + ", ");
		System.out.println();
	}
}