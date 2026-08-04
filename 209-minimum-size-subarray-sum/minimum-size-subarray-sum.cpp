class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int cn = INT_MAX, j = 0, su = 0;
        for (int i = 0; i < nums.size(); i++) {
            su += nums[i];
            while (su >= target) {
                cn = min(cn, i - j + 1);
                su -= nums[j];
                j++;
            }
        }
        return cn == INT_MAX ? 0 : cn;
    }
};