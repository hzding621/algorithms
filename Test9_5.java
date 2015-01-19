import java.util.*;

public class Test9_5 {

	public static String insertCharAt(String str, char c, int pos) {
		String head = str.substring(0, pos);
		String tail = str.substring(pos);
		return head + c + tail;
	}

	public static ArrayList<String> getPerms(String str) {

		if (str == null)
			return null;

		ArrayList<String> perm = new ArrayList<String>();

		if (str.length() == 0) {
			perm.add("");
			return perm;
		}

		char c = str.charAt(0);
		String remainder = str.substring(1);

		ArrayList<String> rems = getPerms(remainder);
		for (String substr : rems) {
			for (int j = 0; j <= substr.length(); j++) {
				perm.add(insertCharAt(substr, c, j));
			}
		}
		return perm;
	}

	public static void main(String []args) {

		ArrayList<String> perms = getPerms("harrypotter");
		for (String s: perms) {
			System.out.println(s);
		}

	}
}