import java.util.*;

public class RectangleArea {


	public static int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
		int x_overlap = Math.max(0, Math.min(C,G) - Math.max(A,E));
		int y_overlap = Math.max(0, Math.min(D,H) - Math.max(B,F));
		int area1 = Math.abs(C-A) * Math.abs(D-B);
		int area2 = Math.abs(G-E) * Math.abs(H-F);
		return area1 + area2 - x_overlap * y_overlap;
	}

	public static void main(String[] args) {
		
	}
}