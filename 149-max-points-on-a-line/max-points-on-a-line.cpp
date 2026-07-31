class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int maxi = 0;
        for (int i = 0; i < points.size() - 1; i++) {
            unordered_map<double, int>out;
            for (int j = i + 1; j < points.size(); j++) {
                double x = (double) (points[j][1] - points[i][1]) / (double) (points[j][0] - points[i][0]);
                if (points[j][0] - points[i][0] == 0) out[abs(x)]++;
                else out[x]++;
            }
            for (auto& it : out) maxi = max(maxi, it.second);
        }
        return maxi + 1;
    }
};