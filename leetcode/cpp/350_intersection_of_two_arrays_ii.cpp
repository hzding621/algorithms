#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int> numsIn1;
        for (int i: nums1) {
            numsIn1[i]++;
        }
        vector<int> intersection;
        for (int i: nums2) {
            if (numsIn1[i] > 0) {
                intersection.push_back(i);
                numsIn1[i]--;
            }
        }
        return intersection;
    }
};

int main() {

    return 0;
}