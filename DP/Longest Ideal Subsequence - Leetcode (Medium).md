## Problem Statement:
You are given a string s consisting of lowercase letters and an integer k. We call a string t ideal if the following conditions are satisfied:

t is a subsequence of the string s.
The absolute difference in the alphabet order of every two adjacent letters in t is less than or equal to k.
Return the length of the longest ideal string.

A subsequence is a string that can be derived from another string by deleting some or no characters without changing the order of the remaining characters.

Note that the alphabet order is not cyclic. For example, the absolute difference in the alphabet order of 'a' and 'z' is 25, not 1.

 

Example 1:

Input: s = "acfgbd", k = 2
Output: 4
Explanation: The longest ideal string is "acbd". The length of this string is 4, so 4 is returned.
Note that "acfgbd" is not ideal because 'c' and 'f' have a difference of 3 in alphabet order.
Example 2:

Input: s = "abcd", k = 3
Output: 4
Explanation: The longest ideal string is "abcd". The length of this string is 4, so 4 is returned.
 

Constraints:

1 <= s.length <= 105
0 <= k <= 25
s consists of lowercase English letters.

## Intuition
 Consider every char as the last element of the subsequence while traversing.

## Approach
DP topdown, bottom up, optimize



## Solutions: 
```c++
    /* 
// LIS - bottom up, successfully got TLE at 74 test case. More happy than getting AC.
// Osthir approach - https://www.youtube.com/watch?v=01nYV8eqxm8
// Intuition : Consider every char as the last element of the subsequence while traversing.

class Solution {
public:
    int longestIdealString(string s, int k) {
        int n = s.size();
        vector<int> t(n, 1);

        for (int i = 0; i < n; i++) {
            for (int j = i - 1; j >= 0; j--) {
                if (abs(s[i] - s[j]) <= k) {
                    t[i] = max (t[i], t[j] + 1);
                }
            }
        }

        return *max_element(t.begin(), t.end());
    }
};

*/

/*
recursion of Lis :- 
TLE at 74
class Solution {
public:
     vector<vector<int>>dp;

    int getLongest(int curr, int prev, string &s, int &k){
        if (curr >= s.size())
            return 0;
        if (dp[curr][prev+1] != -1)
            return dp[curr][prev+1];

        int skip = getLongest(curr+1,prev, s, k);
        int take = 0;
        
        if (prev == -1 || abs(s[curr] - s[prev]) <= k){
            take = 1 + getLongest(curr+1, curr, s, k);
        }
        return dp[curr][prev+1] = max(skip,take);
    }
    int longestIdealString(string s, int k) {
        int n = s.size();
        dp.resize(n, vector<int>(n+1,-1));
        return getLongest(0, -1, s, k);
    }
}
*/

class Solution {
public:
    int longestIdealString(string s, int k) {
        vector<int> store(30);
        int n = s.size();

        for (int i = 0; i < n; i++) {
            int curr_pos = s[i] - 'a';
            int left_range = max(curr_pos - k, 0);
            int right_range = min (curr_pos + k, 25);

            int max_size = 1;
            for (int it = left_range; it <= right_range; it++) {
                store[curr_pos] = max (store[curr_pos], store[it]);
            }
            store[curr_pos] += 1; // counting itself;
        }

        return *max_element(store.begin(), store.end());
    }
};
```
## Problem links:
[Longest Ideal Subsequence](https://leetcode.com/problems/longest-ideal-subsequence/?envType=daily-question&envId=2024-04-25)
## Resources:
- [CodeStoryWithMIK -youtube](https://youtu.be/01nYV8eqxm8?si=YkpWMAYuaV5iVpfg)

## Similar Problem:
- [300. Longest Increasing Subsequence - Leetcode(Medium)](/Dp/Longest%20Increasing%20Subsequence-%20Leetcode%20(Medium))
- [1671. Minimum Number of Removals to Make Mountain Array](https://leetcode.com/problems/minimum-number-of-removals-to-make-mountain-array)
