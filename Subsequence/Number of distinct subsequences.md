## Problem Statement:
Given a string s, return the number of distinct non-empty subsequences of s. Since the answer may be very large, return it modulo 1e9 + 7.

> A subsequence of a string is a new string that is formed from the original string by deleting some (can be none) of the characters without disturbing the relative positions of the remaining characters. (i.e., "ace" is a subsequence of "abcde" while "aec" is not.
 

Example 1:

Input: s = "abc" </br>
Output: 7</br>
Explanation: The 7 distinct subsequences are "a", "b", "c", "ab", "ac", "bc", and "abc". </br>
Example 2:

Input: s = "aba" </br>
Output: 6 </br>
Explanation: The 6 distinct subsequences are "a", "b", "ab", "aa", "ba", and "aba". </br>
Example 3:

Input: s = "aaa" </br>
Output: 3   </br>
Explanation: The 3 distinct subsequences are "a", "aa" and "aaa".
 

Constraints:

1 <= s.length <= 2000 </br>
s consists of lowercase English letters.

## Solution - 1:

```c++
    class Solution {
    public:
        int distinctSubseqII(string s) {
            int n = s.size();
            long long int mod = 1e9 + 7;
            map<char,int> m;
            vector<long long int> dp(n+1);
            
            dp[0] = 1;
            
            for (int i = 0; i < n; i++) {
                dp [i+1] = (dp[i] * 2) % mod;
                
                if (m.find(s[i]) != m.end()) {
                    dp[i + 1] = (dp[i + 1] - dp[m[s[i]]]) % mod;
                }
                
                m[s[i]] = i;
            }
            // for (auto x : dp) cout << x << " "; cout << endl;
            dp[n]--;
            return dp[n] +  ((dp[n] < 0) ? mod : 0);
    }
};
```
---

## Solution - 2:

```c++
    
/* Solution -2  Learned from discussion (Lee's post). */
class Solution {
public:
    int distinctSubseqII(string s) {
        long endsWith[26] = {}, mod = 1e9 + 7;
        
        for (char c : s) {
            endsWith[c - 'a'] = accumulate(begin(endsWith), end(endsWith), 1L) % mod;
        }
        // for (auto x : endsWith) cout << x << " "; cout << endl;
        return accumulate(begin(endsWith), end(endsWith), 0L) % mod;
    }
};


```

## Problem Link :
- [940. Distinct Subsequences II - Leetcode Hard](https://leetcode.com/problems/distinct-subsequences-ii/)
- [Number of distinct subsequences - gfg Hard](https://practice.geeksforgeeks.org/problems/number-of-distinct-subsequences0909/0)

## Resources :
- [GFG - youtube](https://www.youtube.com/watch?v=EDYFAoAo5Nc)
- [Lee's Post](https://leetcode.com/problems/distinct-subsequences-ii/discuss/192017/JavaC%2B%2BPython-DP-4-lines-O(N)-Time-O(1)-Space "Leetcode Discussion")