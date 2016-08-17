#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <stdexcept>

using namespace std;


class Solution {
public:
    int hIndex(vector<int>& citations) {
  	    int n = citations.size();
  	    sort(citations.begin(), citations.end());

  	    for (int h = n; h >= 0; h--) {
  	    	if (h == 0) {
  	    		if (citations.empty() || citations.back() <= 0)
  	    			return h;
  	    	} else if (h == n) {
  	    		if (citations[0] >= n)
  	    			return n;
  	    	} else {
  	    		if (citations[n - h] >= h && citations[n - h - 1] <= h)
  	    			return h;
  	    	}
  	    }
  	    throw invalid_argument("Invalid input");
    }
};

int main() {

	vector<int> v = {};
	Solution sol;
	cout << sol.hIndex(v) << endl;

	return 0;
}