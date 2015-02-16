public class Test9_6 {
	static void paranPerm(int openParan, int closeParan, String s) {
		if (openParan == 0 && closeParan == 0) {
			System.out.println(s);
		}

		if (openParan > 0) {
			paranPerm(openParan-1, closeParan+1, s + "<");	
		}
		if (closeParan > 0) {
			paranPerm(openParan, closeParan-1, s + ">");
		}
	}
	public static void paranPerm(int n) {
		paranPerm(n, 0, "");
	}

	public static void main(String[] args) {
		paranPerm(3);
	}


}