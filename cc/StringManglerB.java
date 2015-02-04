public class StringManglerB {

	public static boolean isVowel(char c) {
		if (c >= 'A' && c <= 'Z')
			c = Character.toLowerCase(c);
		return isVowelLower(c);
	}

	public static boolean isConsonant(char c) {
		if (c >= 'A' && c <= 'Z')
			c = Character.toLowerCase(c);
		return isConsonantLower(c);
	}

	public static boolean isVowelLower(char c) {
		char[] vowels = {'a', 'e', 'i', 'o', 'u'};
		for (int i = 0; i < 5; i++)
			if (vowels[i] == c)
				return true;
		return false;
	}

	public static boolean isConsonantLower(char c) {
		return (isVowelLower(c) == false) && ( c >= 'a' && c <= 'z' );
	}

	public static char prevConsonant(char c) {
		boolean uppercase = false;
		if ( c >= 'A' && c <= 'Z') {
			uppercase = true;
			c = Character.toLowerCase(c);
		}

		char r;
		if ( c == 'a')
			r = 'z';
		else
			r = (char) ( c-1);
		while (isConsonantLower(r) == false) {
			if ( r == 'a')
				r = 'z';
			else
			r = (char) ( r-1);
		}

		if (uppercase == true)
			r = Character.toUpperCase(r);
		return r;

	}

	public static char nextVowel(char c) {
		boolean uppercase = false;
		if ( c >= 'A' && c <= 'Z') {
			uppercase = true;
			c = Character.toLowerCase(c);
		}

		char r = c;
		switch (c) {
			case 'a':
				r = 'e';
				break;
			case 'e':
				r = 'i';
				break;
			case 'i':
				r =  'o';
				break;
			case 'o':
				r ='u';
				break;
			case 'u':
				r = 'a';
				break;
			default:
				break;
		}

		if (uppercase == true)
			r = Character.toUpperCase(r);
		return r;
	}

	public static String convert(String str, int n) {

		// Change each vowels to the n-th vowel after it
		// Change each consonant to the n-th consonant before it

		// From Epic Interview
		
		StringBuilder ret = new StringBuilder();

		for (int i=0; i<str.length(); i++) {
			char c = str.charAt(i);

			if (isVowel(c)) {
				int p = n % 5;
				while (p > 0) {
					c = nextVowel(c);
					p--;
				}
			} else if (isConsonant(c)) {
				int p = n % 21;
				while (p > 0) {
					c = prevConsonant(c);
					p--;
				}
			}

			ret.append(c);

		}

		return ret.toString();

	}


	public static void main(String[] args) {
		System.out.println(convert("abCdEfZUf", 1));
	}
}