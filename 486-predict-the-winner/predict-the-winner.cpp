class Solution {
public:
    bool predictTheWinner(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>>out(n, vector<int>(n, 0));
        for (int i = 0; i < n; i++) out[i][i] = nums[i];
        for (int ch = 1; ch < n; ch++) {
            int i = 0;
            for (int j = ch; j < n && i < n - ch; j++, i++) {
                out[i][j] = max(nums[i] - out[i + 1][j], nums[j] - out[i][j - 1]);
            }
        }
        return out[0][n - 1] >= 0;
    }
};