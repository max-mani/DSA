class Solution {
public:
    int maxProduct(int n) {
        int l1 = -1, l2 = -1;
        while (n > 0) {
            int d = n % 10;
            if (d >= l1) {
                l2 = l1;
                l1 = d;
            } else if (d > l2) {
                l2 = d;
            }
            n /= 10;
        }
        return l1 * l2;
    }
};