#include <iostream>
#include <string>
#include <vector>

using namespace std;

class NumArray {
public:
    NumArray(vector<int> &nums) {
    	for (int i: nums) {
    		sumLeftOf.push_back(i + (sumLeftOf.empty() ? 0 : sumLeftOf.back()));
    	}
    }
    int sumRange(int i, int j) {
        return sumLeftOf[j] - (i == 0 ? 0 : sumLeftOf[i-1]);
    }
private:
	vector<int> sumLeftOf;
};

int main() {

	vector<int> v = {-2, 0, 3, -5, 2, -1};
	NumArray numArray(v);
	cout << numArray.sumRange(0,2) << endl;
	cout << numArray.sumRange(2,5) << endl;

	return 0;
}