class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int, int> out;
        for (int i = 0; i < nums.size(); i++) out[nums[i]]++;
        for (auto x : out) if (x.second > nums.size() / 2) return x.first;
        return 0;
    }
};