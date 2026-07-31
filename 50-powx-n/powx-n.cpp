class Solution {
public:
    double myPow(double x, int N) {
        long long n = N;
        double out = 1;
        if (n < 0) {
            n = -n;
            x = 1/x;
        }
        while (n > 0) {
            if (n % 2 == 1) {
                out *= x;
            }
            x *= x;
            n /= 2;
        }
        return out;
    }
};