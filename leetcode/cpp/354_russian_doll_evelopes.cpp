#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maxEnvelopes(vector<pair<int, int>>& envelopes) {
        using Box = pair<int,int>;

        // sort in asc of width, in desc of height
        sort(envelopes.begin(), envelopes.end(), 
            [](const Box& a, const Box& b) {
                if (a.first == b.first) return a.second > b.second;
                else return a.first < b.first;
            });

        // LIS in height
        vector<int> tail;
        for (int i = 0; i < envelopes.size(); i++) {
            int elem = envelopes[i].second;
            auto it = lower_bound(tail.begin(), tail.end(), elem);
            if (it == tail.end()) {
                tail.push_back(elem);
            } else {
                *it = elem;
            }
        }
        return tail.size();
    }
};


int main() {

    vector<pair<int,int>> vp = {
        {1,1},
        {2,3},
        {4,6},
        {4,5},
        {6,7},
    };
    cout << Solution().maxEnvelopes(vp) << endl;

    return 0;
}