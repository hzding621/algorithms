#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

class Solution {
public:
    vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k) {

        vector<int> result(k);
        int m = nums1.size(), n = nums2.size();
        for (int len1 = max(0, k-n); len1 <= m && len1 <= k; len1++) {
            // len1/len2 can be zero
            auto v1 = maxNumberSingle(nums1, len1);
            auto v2 = maxNumberSingle(nums2, k-len1);
            auto v = merge(v1, v2, k);
            if (lessThan(result, v, 0, 0)) {
                result = v;
            }
        }
        return result;
    }
private:

    vector<int> merge(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<int> result(k);
        for (int i=0, j=0, r=0; r<k; r++) {
            // should compare lexicographically because the they might have equal prefixes
            result[r] = lessThan(nums1, nums2, i, j) ? nums2[j++] : nums1[i++];
        }
        return result;
    }

    bool lessThan(vector<int>& nums1, vector<int>& nums2, int i1, int i2) {
        return lexicographical_compare(nums1.begin() + i1, nums1.end(), 
                                       nums2.begin() + i2, nums2.end());
    }

    vector<int> maxNumberSingle(vector<int>& nums, int k) {
        vector<int> output(k);
        for (int i = 0, j = 0; j < nums.size(); j++) {
            // i: index in output
            // j: index in nums
            // k-i < n-j: there are more letters left in nums than needed in output

            while (i > 0 && k - i < nums.size() - j && nums[j] > output[i-1]) {
                i--;
            }
            if (i < k) {
                output[i] = nums[j];
                i++;
            }
        }
        return output;
    }
};


int main() {

    Solution sol;
    vector<int> v1 = {6, 7};
    vector<int> v2 = {6, 0, 4};
    auto vi = sol.maxNumber(v1, v2, 5);
    for (int i: vi) {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}