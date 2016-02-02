#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:

    vector<int> majorityElement(vector<int>& nums) {

        int n = nums.size();
		if (n == 0)
			return {};
		else if (n == 1)
			return {nums[0]};

        int v1, v2,
            c1 = 0, c2 = 0,
            t1 = -1, t2 = -1;

		for (int i = 0; i < nums.size(); i++) {
            int k = nums[i];
            if (k == v1) {
				c1++;
                t1 = i;
			}
            else if (k == v2) {
				c2++;
                t2 = i;
            }
			else if (c1 == 0) {
				v1 = k;
				c1 = 1;
                t1 = i;
			} else if (c2 == 0) {
				v2 = k;
				c2 = 1;
                t2 = i;
			} else if (t1 < t2){
				c1--;
                t1 = i;
			} else {
                c2--;
                t2 = i;
            }
		}
		vector<int> v;

		if (c1 > 0) {
			int cnt = count(nums.begin(), nums.end(), v1);
			if (cnt > n / 3)
				v.push_back(v1);
		}
		if (c2 > 0) {
			int cnt = count(nums.begin(), nums.end(), v2);
			if (cnt > n / 3)
				v.push_back(v2);
		}
		return v;
    }

};

void print(const vector<int>& v) {
    cout << '[';
    for (int i=0; i<v.size(); i++) {
        if (i > 0)
            cout << ',';
        cout << v[i];
    }
    cout << ']' << endl;

}

int main() {

    Solution sol;
    vector<int> v1 = {1,2,1,1,1,3,3,4,3,3,3,4,4,4};
    print(sol.majorityElement(v1));

    return 0;
}
