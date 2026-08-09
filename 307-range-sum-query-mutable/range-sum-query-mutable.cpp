class NumArray {
    int n;
    vector<int>fin, num;
public:
    NumArray(vector<int>& nums) {
        n = nums.size();
        num.assign(n, 0);
        fin.assign(n + 1, 0);
        for (int i = 0; i < n; i++) update(i, nums[i]);
    }
    
    void update(int index, int val) {
        int add = val - num[index];
        num[index] = val;
        index++;
        while (index <= n) {
            fin[index] += add;
            index += (index & (-index));
        }
    }

    int sum (int index) {
        int s = 0;
        while (index > 0) {
            s += fin[index];
            index -= (index & (-index));
        }
        return s;
    }

    int sumRange(int left, int right) {
        return sum(right + 1) - sum(left);
    }
};