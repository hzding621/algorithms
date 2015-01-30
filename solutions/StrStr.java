public class StrStr {
	public static boolean checkMatch(String haystack, String needle, int index) {
        if (index + needle.length() > haystack.length())
            return false;
        for (int i=0; i<needle.length(); i++) {
            if (haystack.charAt(index+i) != needle.charAt(i))
                return false;
        }
        return true;
    }
    
    public static int strStr(String haystack, String needle) {
        if (needle.length() > haystack.length() )
            return -1;
        for (int i=0; i<=haystack.length() - needle.length(); i++) {
            if (checkMatch(haystack, needle, i) == true)
                return i;
        }
        return -1;
    }
}