class Solution {
public:
    bool wordPattern(string pattern, string s) {
        unordered_map<char, string> out;
        unordered_map<string, char> out1;
        vector<string> ans;
        string t = "";
        for (char i : s) {
            if (i == ' ') {
                if (t != "") {
                    ans.push_back(t);
                    t = "";
                }
            } else t += i;
        }
        if (t != "") ans.push_back(t);
        if (ans.size() != pattern.size()) return false;
        for (int i = 0; i < pattern.size(); i++) {
            if (out.count(pattern[i]) && out[pattern[i]] != ans[i]) return false;
            else if (out1.count(ans[i]) && pattern[i] != out1[ans[i]]) return false;
            else {
                out[pattern[i]] = ans[i];
                out1[ans[i]] = pattern[i];
            }
        }
        return true;
    }
};