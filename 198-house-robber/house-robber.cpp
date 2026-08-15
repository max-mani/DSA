class Solution {
public:
    int rob(vector<int>& nums) {
        int dp2 = 0, dp1 = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            int t = nums[i];
            if (i > 1) t += dp2;
            int nt = dp1;
            dp2 = dp1;
            dp1 = max(t, nt);
        }
        return dp1;
    }
};