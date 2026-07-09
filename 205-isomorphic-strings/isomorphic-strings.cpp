class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char, char> mps, mpt;
        for (int i = 0; i < s.size(); i++) {
            if (mps.count(s[i]) && mps[s[i]] != t[i]) return false;
            if (mpt.count(t[i]) && mpt[t[i]] != s[i]) return false;
            mps[s[i]] = t[i];
            mpt[t[i]] = s[i];
        }
        return true;
    }
};