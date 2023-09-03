>Given an integer n, return an array ans of length n + 1 such that for each i (0 <= i <= n), ans[i] is the number of 1's in the binary representation of i.

 

`Example 1:`

Input: n = 2 </br>
Output: [0,1,1] </br>
Explanation: </br>
0 --> 0 </br>
1 --> 1 </br>
2 --> 10 </br>
`Example 2:`

Input: n = 5 </br>
Output: [0,1,1,2,1,2] </br>
Explanation:</br>
0 --> 0</br>
1 --> 1</br>
2 --> 10</br>
3 --> 11</br>
4 --> 100</br>
5 --> 101
 

Constraints:

0 <= n <= 105
 

Follow up:

- It is very easy to come up with a solution with a runtime of O(n log n). Can you do it in linear time O(n) and possibly in a single pass?</br>
- Can you do it without using any built-in function (i.e., like __builtin_popcount in C++)?


## Solution - 2 (Using DP):
```c++
    /**
# Learned from here - 
https: leetcode.com/problems/counting-bits/discuss/79527/Four-lines-C%2B%2B-time-O(n)-space-O(n)
# Solved using DP
# Delete last set bit. the value we get, it will 1 bit lesser than  than i since we deleted last set bit of i.
**/
class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> ans (n+1, 0);
        for (int i = 1; i <= n; i++) {
               ans[i] = ans[i & (i-1)] + 1; 
        }
        return ans;
    }
};


```



Problem Link: 
- [338. Counting Bits - LeetCode](https://leetcode.com/problems/counting-bits/)

Explanation:
- [Leetcode discussion](https://leetcode.com/problems/counting-bits/discuss/79527/Four-lines-C++-time-O(n)-space-O(n))
- [GFG](https://www.geeksforgeeks.org/count-total-set-bits-in-all-numbers-from-1-to-n-set-3/)


