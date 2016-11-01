#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for (int n: nums) {
            sum += n;
        }
        if (sum % 2 == 1) {
            // sum is odd, cannot be halved
            return false;
        }
        vector<bool> canSum(sum/2+1);
        canSum[0] = true;
        for (int n: nums) {
            for (int k = sum / 2; k >= n; k--) {
                if (canSum[k - n]) {
                    canSum[k] = true;
                }
            }
        }
        return canSum(sum/2);
    }
};

int main() {


    return 0;
}