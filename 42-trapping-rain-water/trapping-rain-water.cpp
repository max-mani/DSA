class Solution {
public:
    int trap(vector<int>& height) {
        int l = 0, r = height.size() - 1, lm = height[l], rm = height[r], out = 0;
        while (l < r) {
            if (lm < rm) {
                l++;
                lm = max(lm, height[l]);
                out += lm - height[l];
            } else {
                r--;
                rm = max(rm, height[r]);
                out += rm - height[r];
            }
        }
        return out;
    }
};