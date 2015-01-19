import java.util.*;

public class Test1_3_2 {
	public static boolean isPermutation(String a, String b) {
		if (a == null && b == null)
			return true;
		else if (a == null || b == null)
			return false;

		HashMap<Character, Integer> amap = new HashMap<Character, Integer>();
		HashMap<Character, Integer> bmap = new HashMap<Character, Integer>();
		countString(a, amap);
		countString(b, bmap);
		return amap.equals(bmap);
	}

	static void countString(String x, HashMap<Character, Integer> map) {
		for (int i=0; i<x.length(); i++) {
			if (map.get(x.charAt(i)) == null) {
				map.put(x.charAt(i), 1);
			}
			else {
				map.put(x.charAt(i), map.get(x.charAt(i))+1);
			}
		}
	}

	public static void main(String[] args) {
		System.out.println(isPermutation("xyz", "zyx"));
		System.out.println(isPermutation("1234567", "7562341"));
		System.out.println(isPermutation("", ""));
		System.out.println(isPermutation("acd", "aef"));

	}
}