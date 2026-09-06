class Solution {
public:
    string reverseVowels(string s) {
        vector<char>vow;
        for (int l = 0; l < s.size(); l++) {
            if (s[l] == 'a' || s[l] == 'A' || s[l] == 'e' || s[l] == 'E' || s[l] == 'i' || s[l] == 'I' || s[l] == 'o' || s[l] == 'O' || s[l] == 'u' || s[l] == 'U') {
                vow.push_back(s[l]);
            }
        }
        reverse(vow.begin(), vow.end());
        int ch = 0;
        for (int l = 0; l < s.size(); l++) {
            if (s[l] == 'a' || s[l] == 'A' || s[l] == 'e' || s[l] == 'E' || s[l] == 'i' || s[l] == 'I' || s[l] == 'o' || s[l] == 'O' || s[l] == 'u' || s[l] == 'U') {
                s[l] = vow[ch];
                ch++;
            }
        }
        return s;
    }
};