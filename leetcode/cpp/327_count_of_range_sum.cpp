#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int countRangeSum(vector<int>& nums, int lower, int upper) {
        if (nums.size() == 0)
            return 0;
        return divideAndConquer(nums, lower, upper, 0, nums.size() - 1);
    }
private:

    int divideAndConquer(vector<int>& nums, int lower, int upper, int startIndex, int endIndex) {

        if (startIndex == endIndex) {
            return isBetween(nums[startIndex], lower, upper);
        }
        if (startIndex + 1 == endIndex) {
            return isBetween(nums[startIndex], lower, upper) 
                 + isBetween(nums[endIndex], lower, upper)
                 + isBetween(nums[startIndex] + nums[endIndex], lower, upper);
        }

        int middleIndex = (startIndex + endIndex) / 2;
        int count = 0;
        count += divideAndConquer(nums, lower, upper, startIndex, middleIndex);
        count += divideAndConquer(nums, lower, upper, middleIndex+1, endIndex);

        vector<long> prefixesOfRightPart = {nums[middleIndex+1]};
        for (int i = middleIndex + 2; i <= endIndex; i++) {
            prefixesOfRightPart.push_back(prefixesOfRightPart.back() + nums[i]);
        }
        sort(prefixesOfRightPart.begin(), prefixesOfRightPart.end());

        vector<long> suffixesOfLeftPart = {nums[middleIndex]};
        for (int i = middleIndex - 1; i >= startIndex; i--) {
            suffixesOfLeftPart.push_back(suffixesOfLeftPart.back() + nums[i]);
        }
        
        for (long e: suffixesOfLeftPart) {
            count += countBetween(prefixesOfRightPart, lower - e, upper - e);
        }

        return count;
    }

    int countBetween(vector<long>& v, long lowerBound, long upperBound) {
        auto upperBoundIter = upper_bound(v.begin(), v.end(), upperBound);
        auto lowerBoundIter = lower_bound(v.begin(), v.end(), lowerBound);
        return upperBoundIter - lowerBoundIter;
    }

    bool isBetween(int item, int lower, int upper) {
        return lower <= item && item <= upper;
    }
};

int main() {

    vector<int> v = {2147483647,-2147483648,-1,0};
    Solution sol;
    cout << sol.countRangeSum(v, -1, 0) << endl;

    return 0;
}