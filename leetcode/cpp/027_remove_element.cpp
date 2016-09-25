#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int i = 0, j = 0;
        while (j < nums.size()) {
            if (nums[j] != val) {
                nums[i] = nums[j];
                i++;
            }
            j++;
        }
        return i;
    }
};

int main() {

    vector<int> v = {3,2,2,3};
    Solution solution;
    int newLen = solution.removeElement(v, 3);
    for (int i = 0; i < newLen; i++) {
        cout << v[i] << " ";
    }
    cout << endl;
}