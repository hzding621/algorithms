public class RemoveElement {

	public static int removeElement(int[] A, int elem) {
		if (A.length == 0)
			return 0;
		
		int i=0, j=0;
		while (true) {
			while (j < A.length && A[j] == elem)
				j++;
			if (j == A.length)
				return i;
			A[i] = A[j];
			i++;
			j++;
			if (j == A.length)
				return i;
	   }
	}

	public static void main(String[] args) {
		System.out.println(removeElement(new int[] {2}, 3));
	}
}