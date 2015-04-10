import java.util.*;

public class GrayCode {

	// Use algorithm: starting from the lowest bit, if flipping the bit results in a new integer, use it
	public static List<Integer> grayCode(int n) {
		HashSet<Integer> added = new HashSet<Integer>();
		List<Integer> sequence = new ArrayList<Integer>();

		int cur = 0;
		added.add(cur);
		sequence.add(cur);
		while (added.size() < Math.pow(2, n)) {
			int mask = 1;
			while (added.contains(cur ^ mask)) {
				mask = mask << 1;
			}
			added.add(cur^mask);
			sequence.add(cur^mask);
			cur = cur^mask;
		}
		return sequence;
	}

	public static void main(String[] args) {
		Helpers.print(grayCode(2));
	}
}