class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int maxi = 0, out = 0;
        for (int i : gain) {
            out += i;
            cout << out << endl;;
            maxi = max(maxi, out);
        }
        return maxi;
    }
};