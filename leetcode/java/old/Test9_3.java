public class Test9_3 {

	static int magicElem(int[] array, int start, int end) {

		if (end < start || start < 0 || end >= array.length) {
			return -1;
		}

		int mid = (start + end) / 2;
		if (array[mid] == mid)
			return mid;

		if (array[mid] > mid) 
			return magicElem(array, start, mid - 1);
		else
			return magicElem(array, mid + 1, end);
	}

	public static int magicElem(int[] array)
	{
		return magicElem(array, 0, array.length-1);
	}

	public static void main(String []args) {
		int []array = new int[] {-40, -20, -1, 1, 2, 3, 5, 7, 9, 12, 13};
		System.out.println("magicElem: " + magicElem(array));
	}


}