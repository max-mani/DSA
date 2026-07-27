class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>>out;
        int n = intervals.size();
        sort(intervals.begin(), intervals.end());
        for (int i = 0; i < n; i++) {
            int l = intervals[i][0], r = intervals[i][1];
            while (i < n - 1 && r >= intervals[i + 1][0]) {
                i++;
                l = min(l, intervals[i][0]);
                r = max(r, intervals[i][1]);
            }
            out.push_back({l, r});
        }
        return out;
    }
};