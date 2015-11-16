#include <iostream>
#include <vector>
#include <stdexcept>

using namespace std;

void moveToIndex(vector<int>& nums) {
  int n = nums.size();
  int i = 0;
  while (i < n) {
    if (nums[i] != i) {
      if (nums[nums[i]] == nums[i])
        throw runtime_error("");
      if (nums[i] >= n || nums[i] < 0)
        throw runtime_error("");
      swap(*(nums.begin() + nums[i]), *(nums.begin() + i));
    } else {
      i++;
    }
  }
}

int main() {
  vector<int> v = {0,5,2,3,1,4};
  moveToIndex(v);
  for (int i: v)
    cout << i << endl;
}
