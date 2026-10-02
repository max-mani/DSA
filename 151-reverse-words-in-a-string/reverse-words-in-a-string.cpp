class Solution {
public:
    string reverseWords(string s) {
        vector<string>out;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] != ' ') {
                string st = "";
                while (i < s.size() && s[i] != ' ') {
                    st += s[i];
                    i++;
                }
                out.push_back(st);
            }
        }
        reverse(out.begin(), out.end());
        string st = "";
        for (string i : out) {
            st += i;
            st += " ";
        }
        return st.substr(0, st.size() - 1);
    }
};