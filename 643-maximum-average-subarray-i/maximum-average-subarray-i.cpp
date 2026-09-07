class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        double out = 0;
        for (int i = 0; i < k; i++) out += nums[i];
        double maxi = out / k;
        for (int i = 0; i < nums.size() - k; i++) {
            out -= nums[i];
            out += nums[i + k];
            maxi = max(maxi, out / k);
        }
        return maxi;
    }
};