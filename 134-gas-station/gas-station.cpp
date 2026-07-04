class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int st = 0, tot = 0, tk = 0;
        for (int i = 0; i < gas.size(); i++) {
            tot += gas[i] - cost[i];
            tk += gas[i] - cost[i];
            if (tk < 0) {
                tk = 0;
                st = i + 1;
            }
        }
        return (tot < 0) ? -1 : st;
    }
};