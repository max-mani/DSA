class Solution {
public:
    int maximumLengthSubstring(string s) {
        int l = 0, maxi = 0;;
        unordered_map<char, int>out;
        for (int i = 0; i < s.size(); i++) {
            out[s[i]]++;
            while (out[s[i]] > 2) {
                out[s[l]]--;
                l++;
            }
            maxi = max(maxi, i - l + 1);
        }
        return maxi;
    }
};