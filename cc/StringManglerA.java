// From Epic Interview

public class StringManglerA {

	public static String convert(String str, String word) {

		// All Vowels to Upper Case 
		// All Consonant not equal to last character of word, to Lower Case
		// All letters equal to last character of word, to Upper Case

		StringBuilder res = new StringBuilder();

		char lastChar = word.charAt(word.length()-1);
		for (int i=0; i<str.length(); i++) {
			char c = str.charAt(i);
			if (isVowel(c)) {
				res.append(Character.toUpperCase(c));
			} else if (c != lastChar && isConsonant(c)) {
				res.append(Character.toLowerCase(c));
			}
			else if (c == lastChar) {
				res.append(Character.toUpperCase(c));
			} else {
				res.append(c);
			}
		}
		return res.toString();
	}

	static char[] vowels = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};

	public static boolean isVowel(char c) {
		for (int i=0; i<5; i++)
			if (c == vowels[i])
				return true;
		return false;
	}

	public static boolean isConsonant(char c) {
		if (isVowel(c) == false) {
			if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
				return true;
		}
		return false;
	}

	public static void main(String[] agrs) {
		System.out.println(convert("asISLFmvas", "aaa"));
	}
}