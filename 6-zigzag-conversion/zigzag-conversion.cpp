class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1 || numRows > s.size()) return s;
        int in = 0, t = 1;
        vector<vector<char>> out(numRows);
        string res = "";
        for (char i : s) {
            out[in].push_back(i);
            if (in == 0) {
                t = 1;
            } else if (in == numRows - 1) {
                t = -1;
            }
            in += t;
        }
        for (auto& i : out) {
            for (char j : i) {
                res += j;
            }
        }
        return res;
    }
};