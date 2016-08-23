#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <utility>

using namespace std;

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> intCounts;
        for (int i: nums) {
            intCounts[i]++;
        }
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> topK;
        for (auto& e: intCounts) {
            topK.push(make_pair(e.second, e.first));
            if (topK.size() > k) {
                topK.pop();
            }
        }
        vector<int> output;
        while (topK.size()) {
            int i = topK.top().second;
            topK.pop();
            output.push_back(i);
        }
        reverse(output.begin(), output.end());
        return output;
    }
};

int main() {

    Solution sol;
    vector<int> v = {1,1,1,2,2,3};
    auto ans = sol.topKFrequent(v, 2);
    for (int i: ans) {
        cout << i << ' ';
    }
    cout << endl;

    return 0;
}