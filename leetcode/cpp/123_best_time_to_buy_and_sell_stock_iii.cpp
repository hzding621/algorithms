#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
	int maxProfit(vector<int>& prices) {
		
		// thanks to 
		// http://blog.csdn.net/fightforyourdream/article/details/14503469

		int n = prices.size();
		if (n == 0)
			return 0;
		vector<int> left(n);
		vector<int> right(n);
		left[0] = 0;
		int min = prices[0];
		for (int i=1; i<n; i++) {
			left[i] = std::max(left[i-1], prices[i]-min);
			min = std::min(min, prices[i]);
		}
		right[n-1] = 0;
		int max = prices[n-1];
		for (int i=n-2; i>=0; i--) {
			right[i] = std::max(right[i+1], max-prices[i]);
			max = std::max(max, prices[i]);
		}

		int ans = 0;
		for (int i=0; i<n; i++) {
			ans = std::max(ans, left[i]+right[i]);
		}
		return ans;
	}
};

int main() {

	Solution s;

	vector<int> test;
	test.push_back(6); //6,1,3,2,4,7
	test.push_back(1);
	test.push_back(3);
	test.push_back(2);
	test.push_back(4);
	test.push_back(7);
	cout << s.maxProfit(test) << endl;

	return 0;
}