class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> out(nums.begin(), nums.end());
        int ans = 0;
        for (int i : out) {
            if (!out.count(i - 1)) {
                int j = i, res = 1;
                while (out.count(1 + j)) {
                    res++;
                    j++;
                }
                ans = max(ans, res);
            }
        }
        return ans;
    }
};