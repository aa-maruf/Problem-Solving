## Problem Statement:
Given an integer array nums, move all the even integers at the beginning of the array followed by all the odd integers.

Return any array that satisfies this condition.

 

Example 1:

Input: nums = [3,1,2,4]</br>
Output: [2,4,3,1]</br>
Explanation: The outputs [4,2,3,1], [2,4,1,3], and [4,2,1,3] would also be accepted.</br>
Example 2:

Input: nums = [0]</br>
Output: [0]
Solution  - 1:
```c++
class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        vector<int>a;
        vector<int>b;
        
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] % 2 == 0)
                a.push_back(nums[i]);
            else
                b.push_back(nums[i]);
        }
        vector<int>ans(nums.size());
        int j = 0;
       
       for (int i = 0; i < a.size(); i++) 
                 ans[j++] = a[i];
       for (int i = 0; i < b.size(); i++) 
                  ans[j++] = b[i];
        return ans;
    }
};
```
Solution :
```c++
/* Two pointer technique*/
class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        for (int i = 0, j = 0; i < nums.size(); i++) {
            if (nums[i] % 2 == 0) {
                swap(nums[i],nums[j]);
                j++;
            }
        }
        return nums;
    }
};
```
---

**Problem link:**
- [905. Sort Array By Parity - Leetcode easy](https://leetcode.com/problems/sort-array-by-parity/)
- [283. Move Zeroes - Leetcode easy](https://leetcode.com/problems/move-zeroes/)
- [Segregate 0s and 1s - GFG easy](https://practice.geeksforgeeks.org/problems/segregate-0s-and-1s5106/1?utm_source=gfg&utm_medium=article&utm_campaign=bottom_sticky_on_article)
- [75. Sort Colors - Leetcode medium](https://leetcode.com/problems/sort-colors/)