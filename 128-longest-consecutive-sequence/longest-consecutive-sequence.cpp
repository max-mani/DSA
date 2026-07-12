class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> out(nums.begin(), nums.end());
        int ans = 0;
        for (int i : out) {
            if (!out.count(i - 1)) {
                int j = 1, res = 1;
                while (out.count(i + j)) {
                    res++;
                    j++;
                }
                ans = max(ans, res);
            }
        }
        return ans;
    }
};