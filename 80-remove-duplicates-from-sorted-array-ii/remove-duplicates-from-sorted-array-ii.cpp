class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.size() <= 2) return nums.size();
        int out = 2;
        for (int i = 2; i < nums.size(); i++) {
            if (nums[i] != nums[out - 2]) nums[out++] = nums[i];
        }
        return out;
    }
};