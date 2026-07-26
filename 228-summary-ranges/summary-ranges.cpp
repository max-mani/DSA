class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string>out;
        for (int i = 0; i < nums.size(); i++) {
            string st = "";
            int j = i;
            st += to_string(nums[i]);
            while (i < nums.size() - 1 && nums[i + 1] == nums[i] + 1) i++;
            if (i - j) {
                st += "->";
                st += to_string(nums[i]);
            }
            out.push_back(st);
        }
        return out;
    }
};