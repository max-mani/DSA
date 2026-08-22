class Solution {
public:
    bool checkDivisibility(int n) {
        int sum = 0, prd = 1, num = n;
        while (n) {
            int d = n % 10;
            sum += d;
            prd *= d;
            n /= 10;
        }
        return num % (sum + prd) == 0;
    }
};