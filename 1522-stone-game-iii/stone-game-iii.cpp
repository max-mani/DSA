class Solution {
public:
    string stoneGameIII(vector<int>& stoneValue) {
        int n = stoneValue.size();
        vector<int>out(n + 3, 0);
        for (int i = n - 1; i >= 0; i--) {
            int t = 0;
            out[i] = INT_MIN;
            for (int j = 0; j < 3 && i + j < n; j++) {
                t += stoneValue[i + j];
                out[i] = max(out[i], t - out[i + j + 1]);
            }
        }
        if (out[0] > 0) return "Alice";
        if (out[0] < 0) return "Bob";
        return "Tie";
    }
};