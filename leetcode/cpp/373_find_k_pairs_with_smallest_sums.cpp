#include <iostream>
#include <queue>
#include <vector>
#include <utility>
#include <climits>

using namespace std;

// sum, aIndex, bIndex
using triple = tuple<int,int,int>;

class Solution {
public:
    vector<pair<int, int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        priority_queue<triple, vector<triple>, greater<triple>> pq;
        int n = nums1.size(), m = nums2.size();
        vector<pair<int,int>> result;
        if (n == 0 || m == 0) {
            return result;
        } 
        pq.push(make_tuple(nums1[0] + nums2[0], 0, 0));
        while (!pq.empty() && result.size() < k) {
            auto trip = pq.top();
            pq.pop();
            int x, y;
            tie(ignore, x, y) = trip;
            if (x < n-1 && y == 0) {
                pq.push(make_tuple(nums1[x+1] + nums2[y], x+1, y));
            } 
            if (y < m-1) {
                pq.push(make_tuple(nums1[x] + nums2[y+1], x, y+1));
            }
            result.push_back(make_pair(nums1[x], nums2[y]));
        }
        return result;
    }
};

int main() {

    Solution sol;
    vector<int> A = {1,7,11}, 
                B = {2,4,6};
    auto ps = sol.kSmallestPairs(A, B,9);
    for (auto& p: ps) {
        cout << p.first << "," << p.second << endl;
    }

    return 0;
}