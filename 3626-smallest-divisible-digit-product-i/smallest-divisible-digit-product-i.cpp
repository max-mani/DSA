class Solution {
public:
    int smallestNumber(int n, int t) {
        while (1) {
            int temp = n;
            int p = (n == 0) ? 0 : 1;
            while (temp > 0) {
                p *= temp % 10;
                temp /= 10;
            }
            if (p % t == 0) return n;
            else n++;
        }
    }
};