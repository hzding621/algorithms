import java.util.*;

public class SortingTest {
	public static void main(String[] args) {
		int[] array = new int[]{6,1,7,9,4,2,8,3,5};
		int[] array2 = array.clone();
		System.out.println(Arrays.toString(array));
		Sorting.mergeSort(array);
		Sorting.quickSort(array2);

		try {
			assertSorted(array);
			assertSorted(array2);
		}
		catch (Exception e)
		{
			System.out.println("Array Unsorted !");
		}
		finally {
			System.out.println(Arrays.toString(array));
			System.out.println(Arrays.toString(array2));
		}
	}
	static void assertSorted(int[] array) throws Exception{
		for (int i=0; i < array.length-1; i++) {
			if (array[i] > array[i+1])
				throw new Exception();
		}
	}
}