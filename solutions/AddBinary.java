public class AddBinary {

	public static String reverseString(String s) {
		StringBuilder str = new StringBuilder();
		for (int i=s.length()-1; i>=0; i--) {
			str.append(s.charAt(i));
		}
		return str.toString();
	}

	public static String addBinary(String a, String b) {

		String x = reverseString(a);
		String y = reverseString(b);

		StringBuilder result = new StringBuilder();

		int i =0;
		int carry = 0;

		while (i <= x.length()-1 && i <= y.length()-1) {

			int c = x.charAt(i) - '0';
			int d = y.charAt(i) - '0';
			int sum = c + d + carry;
			if (sum == 0) {
				result.append('0');
				carry = 0;
			}
			else if (sum == 1) {
				result.append('1');
				carry = 0;
			}
			else if (sum == 2) {
				result.append('0');
				carry = 1;
			}
			else if (sum == 3) {
				result.append('1');
				carry = 1;
			}
			i++;
		}
		
		if (i <= x.length() - 1) {
			while (i <= x.length() - 1) {

				int c = x.charAt(i) - '0';
				int sum = c + carry;
				if (sum == 0) {
					result.append('0');
					carry = 0;
				}
				else if (sum == 1) {
					result.append('1');
					carry = 0;
				}
				else if (sum == 2) {
					result.append('0');
					carry = 1;
				}
				i++;
			}
		} else {
			while (i <= y.length() - 1) {
				int c = y.charAt(i) - '0';
				int sum = c + carry;
				if (sum == 0) {
					result.append('0');
					carry = 0;
				}
				else if (sum == 1) {
					result.append('1');
					carry = 0;
				}
				else if (sum == 2) {
					result.append('0');
					carry = 1;
				}
				i++;
			}
		}

		if (carry == 1)
			result.append('1');

		return reverseString(result.toString());
	}

	public static void main(String[] args) {
		System.out.println(addBinary("11", "11"));
	}
}