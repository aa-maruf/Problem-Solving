> Given an integer array nums, rotate the array to the right by k steps, where k is non-negative.

 

`Example 1:`

Input: nums = [1,2,3,4,5,6,7], k = 3 </br>
Output: [5,6,7,1,2,3,4]

`Explanation:`
rotate 1 steps to the right: [7,1,2,3,4,5,6] </br>
rotate 2 steps to the right: [6,7,1,2,3,4,5] </br>
rotate 3 steps to the right: [5,6,7,1,2,3,4] </br>
Example 2:

Input: nums = [-1,-100,3,99], k = 2 </br>
Output: [3,99,-1,-100] </br>
`Explanation: `
rotate 1 steps to the right: [99,-1,-100,3] </br>
rotate 2 steps to the right: [3,99,-1,-100] 
 

`Constraints`:

1 <= nums.length <= 105 </br>
-231 <= nums[i] <= 231 - 1 </br>
0 <= k <= 105
 

`Follow up:`

Try to come up with as many solutions as you can. There are at least three different ways to solve this problem.
Could you do it in-place with O(1) extra space?

## Solution - 1
```c++
    class Solution {
    public:
        void rotate(vector<int>& v, int k) {
            int n = v.size();
            k = k % n;
            int x = (n - k) % n;
            vector<int> ans = v;
            for (int i = 0; i < n; i++) {
                ans [i] = v[(x++) % n];
            }
            v = ans;
        }
};
```

## Solution - 2
```c++
    //Solution - 2 using reverse function. But Solution-1 is more preferable.
class Solution {
public:
    void rotate(vector<int>& v, int k) {
        k = k% v.size();
        reverse(v.begin(),v.end());
        reverse(v.begin(),v.begin() + k);
        reverse(v.begin() + k,v.end());
        
    }
};
```
#### Problem link: [189. Rotate Array - LeetCode Medium](https://leetcode.com/problems/rotate-array/)