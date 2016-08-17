#include <iostream>
#include <string>
#include <vector>

using namespace std; 


class Solution {
public:
    int hIndex(vector<int>& citations) {
    	if (citations.size() == 0)
    		return 0;
    	if (citations.back() <= 1)
    		return citations.back();
        return hIndexBinarySearchIterative(citations);
    }
private:
	int hIndexBinarySearch(vector<int>& citations, int startIndex, int endIndex) {
		if (startIndex == endIndex) {
			return citations.size() - startIndex;
		} else if (startIndex + 1 == endIndex) {
			if (citations[startIndex] >= citations.size() - startIndex) {
				return citations.size() - startIndex;
			} else {
				return citations.size() - endIndex;
			}
		} else {
			int middleIndex = (startIndex + endIndex) / 2;
			int upperCount = citations.size() - middleIndex;
			if (citations[middleIndex] >= upperCount) {
				// hIndex can be larger
				return hIndexBinarySearch(citations, startIndex, middleIndex);
			} else {
				return hIndexBinarySearch(citations, middleIndex + 1, endIndex);
			}
		} 
	}

	int hIndexBinarySearchIterative(vector<int>& citations) {

		int startIndex = 0, endIndex = citations.size() - 1;

		while (startIndex + 1 < endIndex) {
			int middleIndex = (startIndex + endIndex) / 2;
			int upperCount = citations.size() - middleIndex;
			if (citations[middleIndex] >= upperCount) {
				// hIndex can be larger
				endIndex = middleIndex;
			} else {
				startIndex = middleIndex + 1;
			}
		}

		if (startIndex == endIndex) {
			return citations.size() - startIndex;
		} else if (startIndex + 1 == endIndex) {
			if (citations[startIndex] >= citations.size() - startIndex) {
				return citations.size() - startIndex;
			} else {
				return citations.size() - endIndex;
			}
		} else {
			throw invalid_argument("Illegal State");
		}

	}
};

int main() {


	Solution sol;
	vector<int> v = {0,1,3,5,6};
	cout << sol.hIndex(v) << endl;


	return 0;
}