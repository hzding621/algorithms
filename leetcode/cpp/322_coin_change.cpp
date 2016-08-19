#include <iostream>
#include <vector>
#include <algorithm>

using namespace std; 

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dpFewestCoinForAmount(amount + 1);
        for (int i = 1; i <= amount; i++) {
            int fewestCoin = i+1;
            for (int coinValue: coins) {
                if (i - coinValue >= 0 && dpFewestCoinForAmount[i - coinValue] >= 0) {
                    fewestCoin = min(fewestCoin, 1 + dpFewestCoinForAmount[i - coinValue]);
                }
            }
            if (fewestCoin == i + 1) {
                fewestCoin = -1;
            }
            dpFewestCoinForAmount[i] = fewestCoin;
        }  
        return dpFewestCoinForAmount[amount];
    }
};

int main() {

    vector<int> v = {2};
    int amount = 3;
    Solution sol;
    cout << sol.coinChange(v, amount) << endl;

    return 0;
}