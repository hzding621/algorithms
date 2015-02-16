// https://oj.leetcode.com/problems/generate-parentheses/

import java.util.*;

public class GenerateParentheses {

	public static List<String> generateParenthesis(int n) {

		if (n == 0)
			return new ArrayList<String>();

		Set<String> set = new HashSet<String>();
		set.add("()");
		n--;
		while (n>0) {
			Set<String> newSet = new HashSet<String>();	
			for (String s: set) {
				for (int i=0; i<s.length(); i++) {
					char p = s.charAt(i);
					if (p == '(') {
						String newS = s.substring(0, i+1) + "()" + s.substring(i+1);	
						if (!newSet.contains(newS)) {
							newSet.add(newS);
						}
					}
				}
				String append = s + "()";
				if (!newSet.contains(append)) {
							newSet.add(append);
				}
				String prepend = "()" + s;
				if (!newSet.contains(prepend)) {
							newSet.add(prepend);
				}
				String around = "(" + s + ")";
				if (!newSet.contains(around)) {
							newSet.add(around);
				}

			}
			set = newSet;
			n--;
		}

		List<String> result = new ArrayList<String>();
		for (String s: set) {
			result.add(s);
		}
		return result;
	}

	public static void main(String[] args) {
		List<String> list = generateParenthesis(3);
		for (String s: list) {
			System.out.println(s);
		}
	}

}