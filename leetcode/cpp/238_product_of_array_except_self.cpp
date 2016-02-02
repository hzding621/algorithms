#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> v(n);
        int folder = 1;
        for (int i = 0; i < n; i++) {
            v[i] = folder;
            folder *= nums[i];
        }
        folder = 1;
        for (int i = n-1; i>=0; i--) {
            v[i] *= folder;
            folder *= nums[i];
        }
        return v;
    }
};

int main() {
    Solution sol;
    vector<int> v = {1,2,3,4};
    vector<int> ret_v = sol.productExceptSelf(v);
    for (int n: ret_v)
        cout << n << " ";
    cout << endl;
}
