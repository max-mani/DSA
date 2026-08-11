class Solution {
public:
    bool winnerSquareGame(int n) {
        vector<bool>dp(n + 1, false);
        for (int i = 0; i <= n; i++) {
            if (!dp[i]) {
                for (int k = 1; k * k <= n - i; k++) dp[i + k * k] = true;
            }
        }
        return dp[n];
    }
};