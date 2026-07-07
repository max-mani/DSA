class Solution {
public:
    bool isSubsequence(string s, string t) {
        int n = s.size(), m = t.size(), j = 0;
        if (n == 0) return true;
        if (n > m) return false;
        for (int i = 0; i < m; i++) {
            if (s[j] == t[i]) j++;
            if (j == n) return true;
        }
        return false;
    }
};