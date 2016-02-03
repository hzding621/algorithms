#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>
#include <climits>


using namespace std;

class Solution {
public:
	int reverse(int x) {
		bool n = x < 0;
		x = n ? -x : x;
		int nx = 0;
		while (x > 0) {
			if (nx > INT_MAX / 10)
				return 0;
			nx *= 10;
			nx += (x % 10);
			x /= 10;
		}
		return n ? -nx : nx;
	}
};

int main() {

	Solution sol;
	vector<int> vi = {1,2,3,10,100,101,225,1534236469};
	for (int i: vi)
		cout << i << " " << sol.reverse(i) << endl;

}