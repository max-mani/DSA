class Solution {
public:
    long long gcdSum(vector<int>& nums) {
        int maxi = 0;
        long long res = 0;
        vector<int> out;
        for (int i = 0; i < nums.size(); i++) {
            maxi = max(maxi, nums[i]);
            out.push_back(gcd(nums[i], maxi));
        }
        sort(out.begin(), out.end());
        int n = nums.size();
        for (int i = 0; i < n / 2; i++) {
            res += gcd(out[i], out[n - i - 1]);
        }
        return res;
    }
};