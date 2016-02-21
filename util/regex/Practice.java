public class Practice {

	public static void main(String[] args) {
	
		String pattern = "([01])([01]{2})*";
		String text = "111011010";
		System.out.println(text.matches(pattern));

	}
}