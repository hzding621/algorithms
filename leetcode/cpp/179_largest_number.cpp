#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>
#include <stdexcept>

using namespace std;

class Solution {
public:

    // https://leetcode.com/discuss/43082/short-32ms-c-solution-using-lexicographic-comparison
    string largestNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end(), [](int i, int j) {
            string si = to_string(i);
            string sj = to_string(j);
            return si + sj > sj + si;
        });
        stringstream ss;
        for (int i: nums)
            ss << i;
        string result = ss.str();
        return result.front() == '0' ? "0" : result;
    }
};

int main() {

    Solution sol;
    vector<int> v = {1,1,1,1,1,1,1,1,1,1,1,1,
        1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
            1,1,1,1,1,1,1,1,1,1,1,1,1};
    cout << sol.largestNumber(v) << endl;

    return 0;
}
