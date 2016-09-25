#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i = 0, j = 0;
        while (j < nums.size()) {
            if (j == 0 || nums[j] != nums[j-1]) {
                nums[i] = nums[j];
                i++;
            }
            j++;
        }
        return i;
    }
};

int main() {

    vector<int> v = {1,1,2,2,2,3,4,4,4,5,6,6,7,7,7,8};
    Solution solution;
    int newLen = solution.removeDuplicates(v);
    for (int i = 0; i < newLen; i++) {
        cout << v[i] << " ";
    }
}