import java.util.*;

public class SimplifyPath {

	public static String simplifyPath(String path) {

		ArrayList<String> stack = new ArrayList<String>();

		String[] paths = path.split("/");
		for (int i=0; i<paths.length; i++) {

			String p = paths[i];
			if (p.length() == 0 || p.equals("."))
				continue;

			if (p.equals("..")) {
				if (stack.size() > 0)
					stack.remove(stack.size()-1);
			} else {
				stack.add(p);
			}
		}

        
		StringBuilder str = new StringBuilder();
		str.append('/');
		for (String s: stack) {
			str.append(s);
			str.append('/');
		}
		if (str.length() > 1)
		    str.deleteCharAt(str.length()-1);
		return str.toString();

	}

	public static void main(String[] args) {

		System.out.println(simplifyPath("/a/./b/../../c/"));
		
	}

}