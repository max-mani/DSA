class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size(), ans = 1;;
        vector<int> maxi(n + 1, 1);
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (nums[i] > nums[j]) maxi[i] = max(maxi[i], maxi[j] + 1);
            }
            ans = max(ans, maxi[i]);
        }
        return ans;
    }
};