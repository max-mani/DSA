class Solution {
public:
    int minimumPushes(string word) {
        int n = word.size();
        int out = 0, ch = 1;
        while (n > 0) {
            out += min(n, 8) * ch;
            ch++;
            n -= 8;
        }
        return out;
    }
};