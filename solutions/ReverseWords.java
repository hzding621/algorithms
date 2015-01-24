// https://oj.leetcode.com/problems/reverse-words-in-a-string/

public class ReverseWords {

	public static String reverseWords(String s) {
        
        StringBuilder reversedStr = new StringBuilder();
        StringBuilder cache = new StringBuilder();
        for (int i=0; i<s.length(); i++) {
            char c = s.charAt(i);
            if ( Character.isWhitespace(c)) {
                if (cache.length() > 0) {
                    reversedStr.insert(0, ' ');
                    reversedStr.insert(0, cache.toString());
                    System.out.println(reversedStr);
                    cache = new StringBuilder();
                }   
            }
            else {
                cache.append(c);
            }
        }

        if (cache.length() > 0) {
	        reversedStr.insert(0, ' ');
	        reversedStr.insert(0, cache.toString());
        }
        
        if (reversedStr.length()>0)
            reversedStr.deleteCharAt(reversedStr.length()-1);
        return reversedStr.toString();
    }

    public static void main(String[] args) {
    	System.out.println(reverseWords("a b c d"));
    }

}