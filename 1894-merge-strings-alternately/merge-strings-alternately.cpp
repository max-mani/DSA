class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        string st = "";
        int n = word1.size(), m = word2.size(), i = 0;
        while (i < n || i < m) {
            if (i < n) st += word1[i];
            if (i < m) st += word2[i];
            i++;
        }
        return st;
    }
};