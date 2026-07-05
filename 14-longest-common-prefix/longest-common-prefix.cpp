class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        sort(strs.begin(), strs.end());
        string out = "", l = strs[0], r = strs[strs.size() - 1];
        for (int i = 0; i < min(l.size(), r.size()); i++) {
            if (l[i] != r[i]) return out;
            out += l[i];
        }
        return out;
    }
};