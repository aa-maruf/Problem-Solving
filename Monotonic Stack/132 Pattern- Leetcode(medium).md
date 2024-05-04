## Problem Statement:
Given an array of n integers nums, a 132 pattern is a subsequence of three integers nums[i], nums[j] and nums[k] such that i < j < k and nums[i] < nums[k] < nums[j].

Return true if there is a 132 pattern in nums, otherwise, return false.

 
```
Example 1:

Input: nums = [1,2,3,4]
Output: false
Explanation: There is no 132 pattern in the sequence.
```

```
Example 2:

Input: nums = [3,1,4,2]

Output: true
Explanation: There is a 132 pattern in the sequence: [1, 4, 2].
```

```
Example 3:

Input: nums = [-1,3,2,0]
Output: true
Explanation: There are three 132 patterns in the sequence: [-1, 3, 2], [-1, 3, 0] and [-1, 2, 0].
 
```
Constraints:

$$ n == nums.length $$
$$ 1 <= n <= 2 * 10^{5} $$
$$ -10^{9} <= nums[i] <= 10^{9} $$



## Solutions:
### Solve - 1: 
```c++
// Brute force O(n3)
class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        int n = nums.size();
        for (int i = 0; i < n - 2; i++) {
            for (int j = i + 1; j < n - 1; j++) {
                if (nums[i] < nums[j]) {
                    for (int k = j + 1; k < n; k++) {
                        if (nums[i] < nums[k] and nums[k] < nums[j]) {
                            return true;
                        }
                    }
                }
            }
        }

        return false;
    }
};
```
### Solve - 2 
```c++
// optimise O(n2), we will take first element as minimum.
class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        int n = nums.size();
        int num1 = nums[0];
        for (int j = 1; j < n - 1; j++) {
            num1 = min(num1, nums[j]);
            for (int k = j + 1; k < n; k++) {
                if (num1 < nums[k] and nums[k] < nums[j]) {
                    return true;
                }
            }
        }
        return false;
    }
};
```

### Solve -3 
```c++

// MONOTONIC STACK
// num_i < num_k < num_j
// i < j < k
// monotonic stack: we are iterating from back because 
// we will detect max 2 elements [num_k, num_j] first 
// then we will search for min value [num_i]
// In terms of iteration forward it wasn't possible.
// because we can't compare num_i with num_j to check is it min or not
// as num_i can be smaller than num_j but it could be greater or equal to num_k


class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        int n = nums.size();
        int num_k = INT_MIN;
        stack<int> st;
        for (int i = n -1; i >= 0; i--) {
            if (nums[i] < num_k) return true;
            while (!st.empty() and nums[i] > st.top()) {
                num_k = st.top();
                st.pop();
            }
            st.push(nums[i]);
        }
        return false;
    }
};
```
## Problem links:
- [456. 132 Pattern](https://leetcode.com/problems/132-pattern/description/)

## Resources:
- [MIK's video](https://www.youtube.com/watch?v=RZXxX1EU364)
