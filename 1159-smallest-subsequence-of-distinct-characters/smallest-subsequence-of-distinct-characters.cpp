class Solution {
public:
    string smallestSubsequence(string s) {
        vector<int> out(26);
        vector<bool> res(26, false);
        string ans = "";
        for (int i = 0; i < s.size(); i++) out[s[i] - 'a'] = i;
        for (int i = 0; i < s.size(); i++) {
            if (res[s[i] - 'a']) continue;
            while (!ans.empty() && ans.back() > s[i] && out[ans.back() - 'a'] > i) {
                res[ans.back() - 'a'] = false;
                ans.pop_back();
            }
            ans += s[i];
            res[s[i] - 'a'] = true;
        }
        return ans;
    }
};
