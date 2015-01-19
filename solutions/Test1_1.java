public class Test1_1 {

	public static boolean uniqueCharacter(String x) {
		// Assume ASCII string
		if (x.length() > 256)
			return false;

		boolean[] char_set = new boolean[256];
		for (int i = 0; i < x.length(); i++)
		{
			int j = x.charAt(i);
			if (char_set[j] == true)
				return false;
			char_set[j] = true;
		}

		return true;
	}

	public static void main (String []args) {
		System.out.println("Testing...");
		System.out.println("xyz: " + uniqueCharacter("xyz"));
		System.out.println("xxz: " + uniqueCharacter("xxz"));
	}
}