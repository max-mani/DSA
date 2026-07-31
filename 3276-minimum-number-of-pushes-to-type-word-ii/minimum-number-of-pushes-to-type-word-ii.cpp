class Solution {
public:
    int minimumPushes(string word) {
        vector<int>out(26, 0);
        for (char i : word) out[i - 'a']++;
        sort(out.begin(), out.end(), greater<int>());
        int ans = 0;
        for (int i = 0; i < 26; i++) {
            if (out[i] == 0) break;
            ans += out[i] * ((i / 8) + 1);
        }
        return ans;
    }
};