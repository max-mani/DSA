class Solution {
public:
    int climbStairs(int n) {
        int l1 = 1;
        int l2 = 2;
        if (n <= 2) return n;
        for (int i = 3; i <= n; i++) {
            int temp = l1 + l2;
            l1 = l2;
            l2 = temp;
        }
        return l2;
    }
};