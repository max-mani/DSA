class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0 || (x != 0 && x % 10 == 0)) return false;
        int out = 0;
        while (x > out) {
            out = out * 10 + x % 10;
            x /= 10;
        }
        return out == x || out / 10 == x;
    }
};