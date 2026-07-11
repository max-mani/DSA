class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_set<int> out;
        for (int i = 0; i < nums.size(); i++) {
            if (i > k) out.erase(nums[i - k - 1]);
            if (out.count(nums[i])) return true;
            out.insert(nums[i]);
        }
        return false;
    }
};