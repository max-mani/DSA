class Solution {
public:
    int trailingZeroes(int n) {
        int out = 0;
        while (n > 0) {
            n /= 5;
            out += n;
        }
        return out;
    }
};