class Solution {
public:
    int gcdOfOddEvenSums(int n) {
        int a = 0, b = 0;
        for (int i = 1; i <= 2 * n; i++) {
            if (i % 2 == 1) a += i;
            else b += i;
        }
        return gcd(a, b);
    }
};