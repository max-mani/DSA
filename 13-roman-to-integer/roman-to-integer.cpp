class Solution {
public:
    int mp(char c) {
        switch (c) {
            case 'I': return 1;
            case 'V': return 5;
            case 'X': return 10;
            case 'L': return 50;
            case 'C': return 100;
            case 'D': return 500;
            default: return 1000;
        }
    }
    int romanToInt(string s) {
        int out = 0;
        for (int i = 0; i < s.size() - 1; i++) {
            if (mp(s[i]) < mp(s[i + 1])) out -= mp(s[i]);
            else out += mp(s[i]);
        }
        return out + mp(s[s.size() - 1]);
    }
};