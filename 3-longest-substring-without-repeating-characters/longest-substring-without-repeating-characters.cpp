class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int maxi = 0, l = 0;
        unordered_map<char, int>out;
        for (int r = 0; r < s.size(); r++) {
            out[s[r]] += 1;
            while (out[s[r]] > 1) {
                out[s[l]]--;
                l++;
            }
            maxi = max(maxi, r - l + 1);
        }
        return maxi;
    }
};