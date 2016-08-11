#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

class Solution {
private:
	class BinaryIndexTree {
	public:
		BinaryIndexTree(int n) 
			: _tree(n+1) {}

		void increment(int i, int diff) {
			i = i+1;
			while (i < _tree.size()) {
				_tree[i] += diff;
				i += (i & -i);
			}
		}

		int sum(int i) {
			i = i+1;
			int sum = 0;
			while (i > 0) {
				sum += _tree[i];
				i -= (i & -i);
			}
			return sum;
		}
	private:
		vector<int> _tree;
	};

public:
    vector<int> countSmaller(vector<int>& nums) {
    	int n = nums.size();
    	vector<int> numsSorted = nums;
    	sort(numsSorted.begin(), numsSorted.end());
    	unordered_map<int, int> valueToOrder;
    	for (int i=0; i<n; i++) {
    		valueToOrder[numsSorted[i]] = i;
    	}

    	BinaryIndexTree tree(n+1);
    	vector<int> smallerRightOf;
    	for (int i=n-1; i>=0; i--) {
    		smallerRightOf.push_back(tree.sum(valueToOrder[nums[i]]-1));
    		tree.increment(valueToOrder[nums[i]], 1);
    	}
    	reverse(smallerRightOf.begin(), smallerRightOf.end());
    	return smallerRightOf;
    }
};

int main() {

	Solution sol;
	vector<int> v = {5,2,6,1};
	vector<int> ans = sol.countSmaller(v);
	for (int i: ans) {
		cout << i << ',';
	}
	cout << endl;

	return 0;
}