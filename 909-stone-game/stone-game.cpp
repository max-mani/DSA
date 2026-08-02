class Solution {
public:
    bool stoneGame(vector<int>& piles) {
        int n = piles.size();
        vector<vector<int>>out(n, vector<int>(n, 0));
        for (int i = 0; i < n; i++) out[i][i] = piles[i];
        for (int ch = 1; ch < n; ch++) {
            int i = 0;
            for (int j = ch; j < n; i++, j++) {
                out[i][j] = max(piles[i] - out[i + 1][j], piles[j] - out[i][j - 1]);
            }
        }
        return out[0][n - 1] > 0;
    }
};