class Solution {
public:
    int jump(vector<int>& nums) {
        int l = 0, r = 0, out = 0;
        while (r < nums.size() - 1) {
            int end = 0;
            for (int i = l; i <= r; i++) end = max(end, i + nums[i]);
            l = r + 1;
            r = end;
            out++;
        }
        return out;
    }
};