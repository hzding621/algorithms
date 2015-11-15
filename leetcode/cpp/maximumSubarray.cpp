class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;
        vector<int> maxEndedAt(n);
        maxEndedAt[0] = nums[0];
        for (int i=1; i<n; i++) {
            maxEndedAt[i] = nums[i] + max(0, maxEndedAt[i-1]);
        }
        int max = maxEndedAt[0];
        for (int i=0; i<n; i++)
            max = std::max(max, maxEndedAt[i]);
        return max;
    }
};