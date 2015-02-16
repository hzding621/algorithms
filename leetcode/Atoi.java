public class Atoi {
	
	public int atoi(String str) {
		
		if (str.length() == 0)
			return 0;
			
		str = str.trim();
		
		int value = 0;
		
		boolean negative = false;
		
		if (str.charAt(0) == '+' )
			str = str.substring(1);
		else if (str.charAt(0) == '-') {
			negative = true;
			str = str.substring(1);
		}

		int count = 0;
		for (int i=0; i<str.length(); i++) {
			char c = str.charAt(i);
			if ( c < '0' || c > '9' )
				break;
			int x = c - '0';
			if (negative == false) {
				count++;
				if (count == 11)    // overflow
					return Integer.MAX_VALUE;
				value = value * 10 + x;
				if (value < 0)
					return Integer.MAX_VALUE; // overflow
			} 
			else {
				count++;
				if (count == 11)    // overflow
					return Integer.MIN_VALUE;
				value = value * 10 - x;
				if (value > 0)
					return Integer.MIN_VALUE; // overflow
			}
			
			
		}
	
		return value;
	}

	public static void main(String[] args) {

		System.out.println(atoi("    -10326662300y"));
	}

}