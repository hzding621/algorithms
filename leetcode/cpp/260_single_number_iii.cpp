#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
  		int aXorb = 0;
  		for (int n: nums)
  			aXorb ^= n;
  		// find least significant bit 
  		int lsb = aXorb & (aXorb - 1) ^ aXorb;
  		int A = 0, B = 0;
  		for (int n: nums) {
  			if (n & lsb) {
  				A ^= n;
  			} else {
  				B ^= n;
  			}
  		}      
  		return vector<int>{A, B};
    }
};

int main() {
	Solution sol;
	vector<int> v = {1,2,1,2,3,4};
	vector<int> ans = sol.singleNumber(v);
	cout << ans[0] << " " << ans[1] << endl;
}
