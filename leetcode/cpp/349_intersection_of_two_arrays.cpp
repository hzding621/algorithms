#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> numsIn1;
        for (int i: nums1) {
            numsIn1.insert(i);
        }
        unordered_set<int> intersection;
        for (int i: nums2) {
            if (numsIn1.count(i)) intersection.insert(i);
        }
        return vector<int>{intersection.begin(), intersection.end()};
    }
};

int main() {

    return 0;
}