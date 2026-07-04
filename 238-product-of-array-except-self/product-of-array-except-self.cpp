class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size(), r = 1;
        vector<int> out(n);
        out[0] = 1;

        for (int i = 1; i < n; i++) out[i] = out[i - 1] * nums[i - 1];
        for (int i = n - 1; i >= 0; i--) {
            out[i] *= r;
            r *= nums[i];
        }

        return out;
    }
};