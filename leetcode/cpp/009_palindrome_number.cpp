#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	bool isPalindrome(int x) {
		int sum = 0, target = x;
		while (x > 0) {
				sum = sum * 10 + x % 10;
				x /= 10;
		}
		return sum == target;
	}
};

int main() {

	vector<int> vi = {555,101,11,2,12344321,123,0};

	Solution sol;

	for (int i: vi)
		cout << i << " " << sol.isPalindrome(i) << endl;

}