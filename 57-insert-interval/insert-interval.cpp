class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> out;
        intervals.push_back(newInterval);
        sort(intervals.begin(), intervals.end());
        for (int i = 0; i < intervals.size(); i++) {
            int l = intervals[i][0], r = intervals[i][1];
            while (i < intervals.size() - 1 && intervals[i + 1][0] <= r) {
                i++;
                r = max(r, intervals[i][1]);
            }
            out.push_back({l, r});
        }
        return out;
    }
};