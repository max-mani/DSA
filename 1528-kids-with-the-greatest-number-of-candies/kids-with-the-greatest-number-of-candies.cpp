class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        int maxi = *max_element(candies.begin(), candies.end());
        vector<bool> out;
        for (int i : candies) {
            if (i + extraCandies >= maxi) {
                out.push_back(true);
            } else {
                out.push_back(false);
            }
        }
        return out;
    }
};