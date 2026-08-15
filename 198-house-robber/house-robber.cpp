class Solution {
public:
    int rob(vector<int>& nums) {
        vector<int>dp(nums.size());
        dp[0] = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            int t = nums[i];
            if (i > 1) t += dp[i - 2];
            int nt = dp[i - 1];
            dp[i] = max(t, nt);
        }
        return dp[nums.size() - 1];
    }
};