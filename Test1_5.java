public class Test1_5 {

	public static String stringCompress(String x) {
		if (x == null || x.isEmpty())
			return x;

		StringBuffer ret = new StringBuffer();
		char cur = x.charAt(0);
		int count = 1;
		for (int i = 1; i < x.length(); i++)
		{
			if (x.charAt(i) == cur)
				count++;
			else {
				ret.append(cur);
				ret.append(count);
				cur = x.charAt(i);
				count = 1;
			}
		}
		ret.append(cur);
		ret.append(count);
		if (ret.length() < x.length())
			return ret.toString();
		else
			return x;
	}

	public static void main(String []args) {
		System.out.println("stringCompress(\"xxxxyyyzz\"): " + stringCompress("xxxxyyyzz"));
		System.out.println("stringCompress(\"xyz\"): " + stringCompress("xyz"));
	}
}