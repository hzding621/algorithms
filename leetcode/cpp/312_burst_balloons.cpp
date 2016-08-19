#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
  int maxCoins(vector<int>& nums) {
    if (nums.size() == 0)
      return 0;

    vector<int> positives = {1};
    for (int i : nums) {
      if (i > 0) {
        positives.push_back(i);
      }
    }
    positives.push_back(1);
    int n = positives.size();
    vector<vector<int>> dp;
    for (int i=0; i<n; i++) {
      dp.emplace_back(n);
    }

    for (int len = 3; len <= n; len++) {
      for (int left = 0; left + len - 1 < n; left++) {
        int right = left + len - 1;
        int maxScore = 0;
        for (int j = left + 1; j < right; j++) {
          int score = positives[left] * positives[j] * positives[right]
                + dp[left][j] + dp[j][right];
          maxScore = max(maxScore, score);
        }
        dp[left][right] = maxScore;
      }
    }

    return dp[0][n-1];
  }
};

int main() {

  vector<int> v = {3, 1, 5, 8};
  Solution sol;
  cout << sol.maxCoins(v) << endl;
  return 0;
}