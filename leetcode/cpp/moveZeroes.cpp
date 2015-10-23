#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int i = 0, j = 0;
        while (j < nums.size()) {
            if (nums[j])
                nums[i++] = nums[j];
            j++;
        }
        while (i < nums.size()) {
            nums[i++] = 0;
        }
    }
};
int main() {
  return 0;
}
