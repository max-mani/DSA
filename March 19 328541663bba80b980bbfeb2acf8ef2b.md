# March 19

# Array:

## Medium:

https://leetcode.com/problems/k-diff-pairs-in-an-array/description/

```cpp
class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        if (k < 0) {
            return 0;
        }
        sort(nums.begin(), nums.end());
        
        int i = 0;
        int j = 1;
        int out = 0;
        
        while (j < nums.size()) {
            if (i == j) {
                j++;
            } else if (nums[j] - nums[i] < k) {
                j++;
            } else if (nums[j] - nums[i] > k) {
                i++;
            } else {
                out += 1;
                i++;
                while (i < nums.size() && nums[i] == nums[i - 1]) {
                    i++;
                }
            }

            if (i >= j) {
                j = i + 1;
            }
        }

        return out;
    }
};
```

https://leetcode.com/problems/subsets/description/

https://leetcode.com/problems/invalid-transactions/description/

https://leetcode.com/problems/jump-game/description/

https://leetcode.com/problems/subarray-sums-divisible-by-k/description/