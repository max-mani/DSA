# March 14

# Array:

## Easy:

https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/description/

```cpp
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit = 0;

        for (int i = 1; i < prices.size(); i++) {
            if (prices[i] > prices[i-1]) {
                profit += prices[i] - prices[i-1];
            }
        }

        return profit;
    }
};
```

https://leetcode.com/problems/running-sum-of-1d-array/description/

```cpp
class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        for (int i = 1; i < nums.size(); i++) {
            nums[i] = nums[i] + nums[i - 1];
        }
        return nums;
    }
};
```

## Medium:

https://leetcode.com/problems/subarray-sum-equals-k/description/

https://leetcode.com/problems/next-permutation/description/

## Hard:

https://leetcode.com/problems/insert-delete-getrandom-o1-duplicates-allowed/description/