#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <utility>

using namespace std;

class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        int n = nums.size();
        int middleIndex = n/2;
        nth_element(nums.begin(), nums.begin() + middleIndex, nums.end());
        int median = *(nums.begin() + middleIndex);

        // embed index mapping into 3-way partitioning
        // perform 3-way partitioning as if on normal indexing
        // swap smaller elements to right, larger elements to left
        int left = 0, right = n - 1, i = 0;
        while (i <= right) {
            if (nums[mappedIndex(i, n)] < median) {
                // smaller, swap to right end
                swap(nums, mappedIndex(right, n), mappedIndex(i, n));
                right--;
            } else if (nums[mappedIndex(i, n)] > median) {
                // larger, swap to left
                swap(nums, mappedIndex(left, n), mappedIndex(i, n));
                left++;
                i++;
            } else {
                i++;
            }
        }
    }
private:
    int mappedIndex(int index, int n) {
        return (1 + 2 * index) % (n | 1);
    }

    void swap(vector<int>& vec, int i, int j) {
        if (i == j) return;
        int val = vec[i];
        vec[i] = vec[j];
        vec[j] = val;
    }
};


int main() {

    vector<int> v = {1, 3, 2, 2, 3, 1, 4, 5, 2, 1, 4, 5, 6};
    
    return 0;
}