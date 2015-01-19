public class Sorting {

	public static void mergeSort(int[] array) {
		int[] helper = new int[array.length];
		mergeSort(array, helper, 0, array.length-1);
	}

	static void mergeSort(int[] array, int[] helper, int low, int high) {
		if (low < high) {
			int mid = (low+high)/2;
			mergeSort(array, helper, low, mid);
			mergeSort(array, helper, mid+1, high);
			merge(array, helper, low, mid, high);
		}
	}

	static void merge(int[] array, int[] helper, int low, int mid, int high) {
		for (int i=low; i <= high; i++)
			helper[i]=array[i];

		int cur = low;
		int leftHead = low;
		int rightHead = mid+1;
		while (leftHead <= mid && rightHead <= high) {
			if (helper[leftHead] <= helper[rightHead]) {
				array[cur] = helper[leftHead];
				leftHead++;
			}
			else {
				array[cur] = helper[rightHead];
				rightHead++;
			}
			cur++;
		} 
		int remaining = mid - leftHead;
		for (int j = 0; j <= remaining; j++) {
			array[cur+j] = helper[leftHead+j];
		}
	}

	public static void quickSort(int[] array) {
		
		quickSort(array, 0, array.length-1);
	}

	static void quickSort(int[] array, int low, int high) {
		if (low < high ) {
			int pivot = partition(array, low, high);
			quickSort(array, low, pivot-1);
			quickSort(array, pivot+1, high);
		}
	}

	static int partition(int[] array, int low, int high) {
		int pivot = (low+high)/2;
		int pivotValue = array[pivot];
		swap(array, pivot, high);

		int cur = low;
		for (int i = low; i <= high-1; i++) {
			if (array[i] <= pivotValue) {
				swap(array, i, cur);
				cur++;
			}
		}
		swap(array, cur, high);
		return cur;

	}

	static void swap(int[] array, int a, int b) {
		int temp = array[a];
		array[a]=array[b];
		array[b] = temp;
	}




}