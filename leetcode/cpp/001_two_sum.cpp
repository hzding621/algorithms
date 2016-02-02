#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
  public:
    vector<int> twoSum(vector<int>& nums, int target) {

        vector<pair<int,int>> v;
        for (int i=0; i<nums.size(); i++) {
            v.push_back(make_pair(nums[i], i));
        }
        sort(v.begin(), v.end(), Solution::compare);
        int i=0, j = nums.size()-1;
        while (i <= j) {
            int sum = v[i].first + v[j].first;
            if (sum == target){
                if(v[i].second < v[j].second)
                    return {v[i].second+1, v[j].second+1};
                else
                    return {v[j].second+1, v[i].second+1};
            }
            else if (sum > target)
                j--;
            else
                i++;
        }
        return {};

    }
  private:
    bool static compare(const pair<int,int>& a, const pair<int,int>& b) {
        return a.first < b.first;
    }

};

void print(const vector<int>& v) {
    for (int i: v)
        cout << i << ' ';
    cout << endl;
}

int main() {

    Solution sol;
    vector<int> v{3,2,4};
    print(sol.twoSum(v, 7));

    return 0;
}
