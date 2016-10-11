import java.util.*;

public class IsomorphicStrings {

	public static boolean isIsomorphic(String s, String t) {
		if (s.length() != t.length())
			return false;
		HashMap<Character, Character> mapping = new HashMap<Character, Character>();
		for (int i=0; i<s.length(); i++) {
			char c = s.charAt(i);
			char d = t.charAt(i);
			if (mapping.containsKey(c)) {
				if (mapping.get(c) != d)
					return false;
			} else {
				if (mapping.containsValue(d))
					return false;
				mapping.put(c, d);
			}
		}
		return true;
	}

	public static void main(String[] args) {
		System.out.println(isIsomorphic("egg","add"));
		System.out.println(isIsomorphic("foo","bar"));
		System.out.println(isIsomorphic("paper","title"));
		System.out.println(isIsomorphic("ab","aa"));
	}
}