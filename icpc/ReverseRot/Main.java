import java.util.*;

public class Main {


	static Map<Character, Character> table = null;

	static void preprocess(){

		if (table == null) {

			table = new HashMap<Character, Character>();

			for (int i=0; i<25; i++) {
				char c = (char)('A' + i);
				char d = (char) (c+1);
				table.put(c,d);
			}
			table.put('.', 'A');
			table.put('Z', '_');
			table.put('_', '.');

		}

	}

	static char getNext(char c, int rounds) {
		
		char d = c;
		while (rounds > 0) {
			d = table.get(d);
			rounds--;
		}
		return d;
	}

	static String nextString(String str, int rounds) {

		StringBuilder sb = new StringBuilder();
		for (int i=0; i < str.length(); i++) {
			sb.append(getNext(str.charAt(i), rounds));
		}
		return sb.toString();
	}

	static String reverseString(String str){

		StringBuilder sb = new StringBuilder();
		for (int i=str.length()-1; i>=0; i--) {

			sb.append(str.charAt(i));

		}
		return sb.toString();


	}


	public static void main(String[] args) {

		preprocess();

		Scanner stdin = new Scanner(System.in);
		int rounds = stdin.nextInt();
		while (rounds != 0) {

			String str = stdin.next();
			// System.out.print(rounds + " ");
			System.out.println(reverseString(nextString(str, rounds)));
			rounds = stdin.nextInt();

		}

	}


}