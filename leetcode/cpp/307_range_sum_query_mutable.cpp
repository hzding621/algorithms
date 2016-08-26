#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class NumArray {

public:
    NumArray(vector<int> &nums) 
    	: _tree(nums.size() + 1) {
        for (int i = 0; i < nums.size(); i++) {
        	updateTree(i+1, nums[i]);
        }
    }
    void update(int i, int val) {
    	int oldVal = sumRange(i, i);
        updateTree(i+1, val - oldVal);
    }
    int sumRange(int i, int j) {
        return readTree(j+1) - readTree(i);
    }

private:
	vector<int> _tree;

	void updateTree(int index, int value) {
		while (index < _tree.size()) {
			_tree[index] += value;
			index += (index & -index);
		}
	}
	int readTree(int index) {
		int sum = 0;
		while (index > 0) {
			sum += _tree[index];
			index -= (index & -index);
		}
		return sum;
	}
};

int main() {

	vector<int> v = {1,2,3};
	NumArray numArray(v);

	cout << numArray.sumRange(0,2) << endl;
	numArray.update(0,5);
	cout << numArray.sumRange(0,0) << endl;

	return 0;
}