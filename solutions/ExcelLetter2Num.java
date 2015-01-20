// https://oj.leetcode.com/problems/excel-sheet-column-number/

public class ExcelLetter2Num {
	static int titleToNumber(String s) {
		int len = s.length();
		if (len == 0)
			return 0;

		if (len == 1)
			return getOrder(s.charAt(0));

		int restOf = titleToNumber(s.substring(1));
		int cum = 1;
		for (int j=0; j<len-1; j++)
			cum *= 26;
		int count = getOrder(s.charAt(0));
		int sum = cum * count;
		return sum + restOf;

	}

	static int getOrder(char c) {
		return c - 'A' + 1;
	}

	public static void main(String[] args) {
		System.out.println(titleToNumber("BA"));
	}
}