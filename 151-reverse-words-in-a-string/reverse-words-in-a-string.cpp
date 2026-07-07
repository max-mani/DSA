class Solution {
public:
    string reverseWords(string s) {
        vector<string> out;
        string ans = "", fin = "";
        for (char i : s) {
            if (i == ' ') {
                if (!ans.empty()) {
                    out.push_back(ans);
                    ans.clear();
                }
            } else {
                ans += i;
            }
        }
        if (!ans.empty()) out.push_back(ans);
        if (out.empty()) return "";
        for (int i = out.size() - 1; i >= 0; i--) {
            fin += out[i];
            if (i != 0) {
                fin += " ";
            }
        }
        return fin;
    }
};