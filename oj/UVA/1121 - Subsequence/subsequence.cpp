#include <iostream>
#include <climits>
#include <vector>
#include <algorithm>
using namespace std;

int minSubArrayLen(int s, vector<int>& nums) {
  int i = 0, j = 0;
  int len = INT_MAX;
  int sum = 0;
  while (true) {
    while (sum < s && i < nums.size()) {
      sum += nums[i++];
    }

    if (sum < s && i == nums.size())
      break;

    len = min(len, i-j);

    do {
      sum -= nums[j++];
    } while (sum >= s);
    len = min(len, i-j+1);

    if ( i == nums.size())
      break;
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
