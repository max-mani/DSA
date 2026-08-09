class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int l = 0, maxi = 0;
        unordered_map<char, int>out(26);
        for (int i = 0; i < s.size(); i++) {
            out[s[i]]++;
            while (out[s[i]] > 1) {
                out[s[l]]--;
                l++;
            }
            maxi = max(maxi, i - l + 1);
        }
        return maxi;
    }
};