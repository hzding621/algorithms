#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int findDuplicate(vector<int>& nums) {
    // 0..n-1 nodes, nums[i]=j: i nodes -> (j-1)th nodes
    // the duplicate has two incoming edges
    int n = nums.size();
    int tort = nums[n-1], hare = nums[nums[n-1]-1];
    while (tort != hare) {
        tort = nums[tort-1];
        hare = nums[nums[hare-1]-1];
    }
    tort = n;
    while (tort != hare) {
        tort = nums[tort-1];
        hare = nums[hare-1];
    }
    return tort;
}

int main() {

    vector<int> v = {1,1,4,3,2};
    cout << findDuplicate(v) << endl;

    return 0;
}