import java.util.*;

public class Anagrams {

	public static String sortString(String s) {
		char[] arr = s.toCharArray();
		Arrays.sort(arr);
		return new String(arr);
	}

	public static List<String> anagrams(String[] strs) {

		HashMap<String, List<String>> hash = new HashMap<String, List<String>>();
		for (String s : strs) {
			String sorted = sortString(s);
			if (!hash.containsKey(sorted)) {
				hash.put(sorted, new ArrayList<String>());
			}
			hash.get(sorted).add(s);
		}

		List<String> ans = new ArrayList<String>();
		for (String s: hash.keySet()) {
			List<String> sl = hash.get(s);
			if (sl.size() > 1)
				ans.addAll(sl);
		}
		return ans;
	}

	public static void main(String[] args) {
		String[] ss = new String[] {"abc", "bca", "bbc"};
		List<String> sl = anagrams(ss);
		for (String s: sl)
			System.out.print(s+" ");
	}
}