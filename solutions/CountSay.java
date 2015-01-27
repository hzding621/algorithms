public class CountSay {
	
	public static int howMany(String str, char c, int start) {
		int i = 0; 
		while (i + start < str.length() && str.charAt(i + start) == c)
			i++;
		return i;
	}
	
	public static String findNext(String str) {
		
		StringBuilder result = new StringBuilder();
		
		int start = 0;
		char c = str.charAt(0);
		int count = howMany(str, c, start);
		while (start + count < str.length() ) {
			result.append(count);
			result.append(c);
			
			start = start + count; 
			c = str.charAt(start);
			count = howMany(str, c, start);
		}
		result.append(count);
		result.append(c);
		
		return result.toString();
	}
	
	public static String countAndSay(int n) {
		String str = "1";
		while (n > 1) {
			str = findNext(str);
			n--;
		}
		return str;
	}

	public static void main(String[] args) {
		System.out.println(countAndSay(1));
		System.out.println(countAndSay(2));
		System.out.println(countAndSay(3));
		System.out.println(countAndSay(4));
		System.out.println(countAndSay(5));
		System.out.println(countAndSay(6));
	}

}