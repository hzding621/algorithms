class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> result;
        result.push_back(vector<int>());
        int i = 0, n = nums.size();
        while (i < n) {
            int num = nums[i];
            int cnt = 1;
            while (++i < n && nums[i] == num)
                cnt++;
            vector<vector<int>> nvs;
            for (auto& v: result) {
                vector<int> nv = v;
                for (int k=0;k<cnt;k++) {
                    nv.push_back(num);
                    nvs.push_back(nv);
                }
            }
            result.insert(result.end(), nvs.begin(), nvs.end());
        }
        return result;
    }
};