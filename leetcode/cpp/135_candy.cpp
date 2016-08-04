#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Solution {
public:

  int candy(vector<int>& ratings) {
    int n = ratings.size();
    vector<int> candies(n);
    candies[0] = 1;
    for (int i = 1; i < n; i++) {
      candies[i] = 1;
      if (ratings[i-1] < ratings[i] && candies[i] <= candies[i-1]) {
        candies[i] = candies[i-1] + 1;
      }
    }

    for (int i = n-2; i >= 0; i--) {
      if (ratings[i+1] < ratings[i] && candies[i] <= candies[i+1]) {
        candies[i] = candies[i+1] + 1;
      }
    }

    int sum = 0;
    for (int i=0; i<n; i++) {
      sum += candies[i];
    }
    return sum;
  }

};

int main() {
	vector<int> v = {1,3,5};
	Solution sol;
	cout << sol.candy(v) << endl;
}