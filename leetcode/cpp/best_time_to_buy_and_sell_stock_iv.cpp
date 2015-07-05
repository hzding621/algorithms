#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {

        // answer from
        // https://leetcode.com/discuss/32338/share-my-c-dp-solution-with-o-kn-time-o-k-space-10ms
        int n = prices.size();
        if (n <= 1)
            return 0;
        if (k <= 0)
            return 0;
        if (k > n / 2) {
            int res = 0;
            for (int i=1; i<n; i++)
                res += max(0, prices[i]-prices[i-1]);
            return res;
        }
        int *buy = new int[k+1],
            *sel = new int[k+1];
        fill_n(buy, k+1, INT_MIN);
        fill_n(sel, k+1, 0);

        int p;
        for (int i=0; i<n; i++) {
            p = prices[i];
            for (int j=k; j>0; j--) {
                sel[j] = max(sel[j], buy[j] + p);
                buy[j] = max(buy[j], sel[j-1] - p);
            }
        }
        int res = sel[k];
        delete[] buy;
        delete[] sel;
        return res;
    }
};

int main() {

    Solution sol;
    vector<int> v = {2,5,4,3,1,7,8,0,2,4,5};
    cout << sol.maxProfit(3, v) << endl;
}
