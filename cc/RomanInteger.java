import java.util.*;

public class RomanInteger {

	static TreeMap<Integer, Character> table = null;

	public static void preprocess() {
		if (table == null ) {

			table = new TreeMap<Integer, Character>();
			table.put(1, 'I');
			table.put(5, 'V');
			table.put(10, 'X');
			table.put(50, 'L');
			table.put(100, 'C');
			table.put(500, 'D');
			table.put(1000, 'M');
		}
	}

	public static String intToRoman(int num) {

		StringBuilder sb = new StringBuilder();
		String rest = null;
		if (num >= 1000) {
			if (num >= 4000)
				return "";
			int count = num / 1000;
			rest = intToRoman(num-count*1000);
			for(int i=0; i<count; i++)
				sb.append(table.get(1000));
			sb.append(rest);
			return sb.toString();
		} else {
			int base = 100;
			while (base > 0) {
				if (num >= base) {

					int count = num / base;
					if (count == 9) {
						rest = intToRoman(num-9*base);
						sb.append(table.get(base));
						sb.append(table.get(10 * base));
						sb.append(rest);
						return sb.toString();
					} else if (count >= 5) {
						rest = intToRoman(num-5*base);
						sb.append(table.get(5*base));
						sb.append(rest);
						return sb.toString();
					} else if (count == 4) {
						rest = intToRoman(num-4*base);
						sb.append(table.get(base));
						sb.append(table.get(5*base));
						sb.append(rest);
						return sb.toString();
					} else {
						rest = intToRoman(num-count*base);
						for (int j=0; j<count; j++)
							sb.append(table.get(base));
						sb.append(rest);
						return sb.toString();
					}
				} else {
					base /= 10;
					continue;
				}
			}
			return "";
		}
	}

	public static void main(String[] args) {

		preprocess();

		int[] testcases = new int[] {
			225
		};

		for (int i=0; i<testcases.length; i++)
			System.out.println(testcases[i] + ": " + convert(testcases[i]));

	}

}