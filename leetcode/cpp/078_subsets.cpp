class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> result;
        int n = nums.size();
        int k = 1 << n;
        for (int i=0; i<k; i++) {
            vector<int> v;
            int m = i;
            for (int j=0; j<n; j++) {
                if (m & 1)
                    v.push_back(nums[j]);
                m >>= 1;
            }
            result.push_back(v);
        }
        return result;
    }
};