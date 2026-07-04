class Solution {
public:
    bool canJump(vector<int>& nums) {
        int out = nums.size() - 1;
        for (int i = nums.size() - 2; i >= 0; i--) {
            if (i + nums[i] >= out) out = i;
        }
        return out == 0;
    }
};