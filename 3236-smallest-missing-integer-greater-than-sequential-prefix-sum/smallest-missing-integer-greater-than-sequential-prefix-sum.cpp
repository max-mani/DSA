class Solution {
public:
    int missingInteger(vector<int>& nums) {
        int out = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] == nums[i - 1] + 1) out += nums[i];
            else break;
        }
        unordered_set<int>mp(nums.begin(), nums.end());
        while(mp.count(out)) out++;
        return out;
    }
};