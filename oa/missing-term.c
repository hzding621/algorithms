#include <stdio.h>
#include <stdlib.h>

int find(int* array, int n) {
	if (n == 3) {
		return (array[1] - array[0] + array[1]);
	} else {
		int diff2 = array[2] - array[1];
		int diff1 = array[1] - array[0];
		if (diff1 != diff2) {
			int diff3 = array[3] - array[2];
			if (diff3 == diff2)
				return array[1] - diff3;
			else 
				return (2 * array[1] - array[0]);
		} else {
			
			int j = 3;
			for (; j<n ; j++) {
				
				int diffx = array[j] - array[j-1];
				if (diffx != diff1) {
					return array[j-1] + diff1;
				}
				
			}

		}
		
	}
	return -1;
}

int main() {
	/* Enter your code here. Read input from STDIN. Print output to STDOUT */
	int n;
	scanf("%d\n", &n);
	int *array = malloc(sizeof(int) * n);
	int j=0;
	for(; j<n; j++) {
		scanf("%d ", array+j);
	}
	printf("%d\n", find(array, n));
	return 0;
}