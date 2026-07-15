class Solution {
public:
    string simplifyPath(string path) {
        vector<string> out, res;
        string pat = "/";
        for (int i = 0; i < path.size(); i++) {
            if (path[i] != '/') {
                string ans = "";
                while (i < path.size() && path[i] != '/') {
                    ans += path[i];
                    i++;
                }
                out.push_back(ans);
                i--;
            }
        }
        for (string i : out) {
            if (i == ".." && !res.empty()) {
                res.pop_back();
            } else if (i != "" && i != "." && i != "..") {
                res.push_back(i);
            }
        }
        if (res.empty()) {
            return pat;
        }
        for (int i = 0; i < res.size() - 1; i++) {
            pat += res[i];
            pat += "/";
        }
        pat += res[res.size() - 1];
        return pat;
    }
};