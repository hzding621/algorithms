#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int findMinHelper(vector<int>& num, int begin, int end) {
	if (begin == end)
		return num[begin];
	if (begin + 1 == end)
		return min(num[begin], num[end]);
	int mid = (begin + end) / 2;
	if (num[begin] < num[mid] && num[mid] < num[end])
		return num[begin];
	else if (num[begin] < num[mid])
		return findMinHelper(num, mid+1, end);
	else 
		return findMinHelper(num, begin, mid);
}

int findMin(vector<int>& num) {
	return findMinHelper(num, 0, num.size()-1);
}

void rotate(vector<int>& nums, int k) {
    k %= nums.size();
    reverse(nums.begin(), nums.begin()+nums.size()-k);
    reverse(nums.begin()+nums.size()-k, nums.end());
    reverse(nums.begin(), nums.end());
}

int main() {
	vector<int> v = {1,2,3,4,5,6,7,8};
	for (int k=0; k<v.size(); k++) {
		vector<int> vv = v;
		rotate(vv, k);
		cout << findMin(vv) << endl;
	}
}