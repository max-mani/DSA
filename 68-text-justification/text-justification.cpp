class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        int n = words.size(), i = 0;
        vector<string> ans;
        while (i < n) {
            int j = i, l = 0;
            while (j < n && l + words[j].size() + j - i <= maxWidth) {
                l += words[j].size();
                j++;
            }
            int s = maxWidth - l, g = j - i - 1;
            string line = "";
            if (g == 0 || j == n) {
                for (int k = i; k < j; k++) {
                    line += words[k];
                    if (k != j - 1) line += " ";
                }
                while (line.size() < maxWidth) line += " ";
            } else {
                int se = s / g, e = s % g;
                for (int k = i; k < j; k++) {
                    line += words[k];
                    if (k != j - 1) {
                        int a = se + (e > 0 ? 1 : 0);
                        line += string(a, ' ');
                        if (e > 0) e--;
                    }
                }
            }
            ans.push_back(line);
            i = j;
        }
        return ans;
    }
};