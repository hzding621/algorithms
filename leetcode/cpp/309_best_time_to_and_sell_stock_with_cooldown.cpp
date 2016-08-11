#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {

    	int n = prices.size();
        vector<int> maxProfitStartAt(n+1);
        int maxProfitOfAll = 0;
        maxProfitStartAt[n] = 0;
        for (int i = n-2; i >= 0; i--) {
        	int maxProfitIfBuy = 0;
        	for (int j = i+1; j < n; j++) {
        		int singleProfit = prices[j] - prices[i];
        		int futuereProfit = (j < n-1 ? maxProfitStartAt[j+2] : 0); 
        		maxProfitIfBuy = max(maxProfitIfBuy, singleProfit + futuereProfit);
        	}
        	maxProfitStartAt[i] = max(maxProfitIfBuy, maxProfitStartAt[i+1]);
        	maxProfitOfAll = max(maxProfitOfAll, maxProfitStartAt[i]);
        }
        return maxProfitOfAll;
    }
};

int main() {

	vector<int> v = {6,1,6,4,3,0,2};
	Solution sol;
	cout << sol.maxProfit(v) << endl;

	return 0;
}