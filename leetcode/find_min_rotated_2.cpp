#include <iostream>
#include <algorithm>
#include <vector>

using std::vector;

class Solution {
public:

	int findMin(vector<int> &num, int lower, int upper) {
		if (lower == upper)
			return num[lower];
		else if (lower + 1 == upper)
			return std::min(num[lower], num[upper]);

		int mid = (lower + upper) / 2;
		if ( num[mid] == num[lower] ) {
			int min1 = findMin(num, lower, mid-1);
			int min2 = findMin(num, mid+1, upper);
			return std::min(min1, min2);
		} 
		else if ( num[mid] > num[lower] ) {
			if ( num[upper] >= num[mid] )
				return num[lower]; 
			else 
				return findMin(num, mid+1, upper);
		} else {
			return findMin(num, lower, mid);
		}

	}
	int findMin(vector<int> &num) {
        return findMin(num, 0, num.size()-1);
    }
};

int main() {

	vector<int> num = {1,2,3};

	return 0;
}