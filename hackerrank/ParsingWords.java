import java.io.*;
import java.util.*;
public class ParsingWords {
		
	public static boolean isWord(String s) {
		for (int j=0; j<s.length(); j++) {
			char c = s.charAt(j);
			if (c < 'a' || c > 'z')
				return false;
		}
		return true;
	}
		
	public static void initialize(Map<Character, Integer> map) {
		for (int j=0; j<26; j++) {
			char c = (char)('a' + j);
			map.put(c, 0);
		}
	}    
		
	public static void processLetters(String s, Map<Character, Integer> map) {
		for (int j=0; j<s.length(); j++) {
			char c = s.charAt(j);
			int curCount = map.get(c);
			map.put(c, curCount + 1);
			
		}
	}    
		
	public static void main(String args[] ) throws Exception {
		/* Enter your code here. Read input from STDIN. Print output to STDOUT */
		Scanner stdin = new Scanner(System.in);
		Map<String, Integer> data = new TreeMap<String, Integer>();
		Map<Character, Integer> letterMap = new TreeMap<Character, Integer>();
		initialize(letterMap);
		int count = 0;
		while (stdin.hasNext()) {
			String s = stdin.next();
			if (isWord(s)) {
				if (data.containsKey(s)) {
					int curCount = data.get(s);
					data.put(s, curCount + 1);
				} else {
					data.put(s, 1);
				}
				processLetters(s, letterMap);
				count++;
			}
		}
		System.out.println(count);
		System.out.println("words");
		for (Map.Entry<String, Integer> e: data.entrySet()) {
			System.out.println(e.getKey() + " " + e.getValue());
		} 
		System.out.println("letters");
		for (Map.Entry<Character, Integer> f: letterMap.entrySet()) {
			System.out.println(f.getKey() + " " + f.getValue());
		}
	}
}