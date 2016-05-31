#include <iostream>
#include <climits>
#include <vector>
#include <algorithm>
using namespace std;

int minSubArrayLen(int s, vector<int>& nums) {
  int i = 0, j = 0, sum = 0, n = nums.size();
  int len = INT_MAX;
  while (i < n) {
      while (sum < s && i < n) {
          sum += nums[i++];
      }
      if (sum < s && i == n)
          break;
      while (sum >= s) {
          sum -= nums[j++];
      }
      len = min(len, i-j+1);
  }
  return len == INT_MAX ? 0 : len;
}

int main() {
  int n, s;
  while (scanf("%d %d\n", &n, &s) ==2 ) {
    vector<int> v;
    for (int i=0; i<n; i++) {
      int vi;
      scanf("%d", &vi);
      v.push_back(vi);
    }
    cout << minSubArrayLen(s, v) << endl;
  }
}
