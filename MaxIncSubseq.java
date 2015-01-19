import java.util.*;

public class MaxIncSubseq {
	public static ArrayList<Integer> getLIS(ArrayList<Integer> array) {
		
		ArrayList<ArrayList<Integer>> solutions = new ArrayList<ArrayList<Integer>>();
		for(int i=0; i<array.size(); i++)
			solutions.add(null);
		maxIncSubseqFillTable(array, solutions, 0);

		ArrayList<Integer> bestFound = null;
		for (int i=0; i<array.size(); i++)
			bestFound = longerSeq(bestFound, solutions.get(i));

		return bestFound;
	}

	static void maxIncSubseqFillTable(ArrayList<Integer> array, ArrayList<ArrayList<Integer>> solutions, int index){
		if (index < 0 || index >= array.size())
			return;
		int currentElem = array.get(index);

		ArrayList<Integer> bestFound = null;
		for (int i=0; i<index; i++) {
			if (array.get(i) <= currentElem) {
				bestFound = longerSeq(bestFound, solutions.get(i));
			}
		}
		ArrayList<Integer> newSolution = new ArrayList<Integer>();
		if (bestFound != null) {
			newSolution.addAll(bestFound);
		}
		newSolution.add(currentElem);
		solutions.set(index, newSolution);
		maxIncSubseqFillTable(array, solutions, index+1);
	}

	static ArrayList<Integer> longerSeq(ArrayList<Integer> a, ArrayList<Integer> b) {
		if (a == null) return b;
		if (b == null) return a;
		return a.size() >= b.size() ? a : b;
	}


	public static void main(String[] args) {
		ArrayList<Integer> array = new ArrayList<Integer>(Arrays.asList(2,4,1,6,5,7,8));
		System.out.println("Input: " + array.toString());
		System.out.println("Output: " + getLIS(array));
	}
}