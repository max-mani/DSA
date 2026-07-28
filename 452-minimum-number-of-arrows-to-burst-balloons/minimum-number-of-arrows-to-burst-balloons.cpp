class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(), points.end());
        int out = 0;
        for (int i = 0; i < points.size(); i++) {
            int l = points[i][0];
            int r = points[i][1];
            while (i < points.size() - 1 && points[i + 1][0] <= r) {
                i++;
                r = min(r, points[i][1]);
            }
            out++;
        }
        return out;
    }
};