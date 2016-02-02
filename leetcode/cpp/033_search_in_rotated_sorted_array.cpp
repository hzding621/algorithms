#include <iostream>

using std::cout;
using std::endl;

class Solution {
public:


	int search(int A[], int target, int lower, int upper) {

		int n = upper - lower + 1;

        if (n == 1)
        	return A[lower] == target ? lower : -1;

        if (n == 2) {
        	if (A[lower] == target)
        		return lower;
        	if (A[upper] == target)
        		return upper;
        	return -1;
        }
		
        int mid = (lower + upper) / 2;

        if (A[mid] == target)
        	return mid;

        if (A[mid] > A[lower] && A[mid] < A[upper]) {
        	// ordered array
        	if (A[mid] < target)
        		return search(A, target, mid+1, upper);
        	else 
        		return search(A, target, lower, mid-1);
        }
        else if (A[mid] < A[lower] && A[mid] < A[upper]) {
        	// second case
        	if (target <= A[upper] && target > A[mid])
        		return search(A, target, mid+1, upper);
        	else 
        		return search(A, target, lower, mid-1);
        }
        else {
        	// third case
        	if (target >= A[lower] && target < A[mid])
        		return search(A, target, lower, mid-1);
        	else
        		return search(A, target, mid+1, upper);
        }
	}

    int search(int A[], int n, int target) {
    	return search(A, target, 0, n-1);
    }
};

int main() {

	int A[5] = {4,5,1,2,3};

	Solution a;
	cout << a.search(A, 5, 3) << endl;

	return 0;
}