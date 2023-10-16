## Problem links: 
- [Remove Consecutive Characters](https://practice.geeksforgeeks.org/problems/consecutive-elements2306/1)
- [A. Is It a Cat? - Codeforces](https://codeforces.com/contest/1800/problem/A)
- [1047. Remove All Adjacent Duplicates In String - Leetcode (easy)](https://leetcode.com/problems/remove-all-adjacent-duplicates-in-string/)
  - [2390. Removing Stars From a String - Leetcode Medium](https://leetcode.com/problems/removing-stars-from-a-string/)
- [1209. Remove All Adjacent Duplicates in String II - Leetcode Medium](https://leetcode.com/problems/remove-all-adjacent-duplicates-in-string-ii/)

## Problem Statement:
Given a string S. For each index i(1<=i<=N-1), erase it if s[i] is equal to s[i-1] in the string.

Example 1:

Input:
S = aabb </br>
Output:  ab  </br>
Explanation: 'a' at 2nd position is
appearing 2nd time consecutively.
Similiar explanation for b at
4th position.

Example 2:

Input:
S = aabaa </br>
Output:  aba </br>
Explanation: 'a' at 2nd position is
appearing 2nd time consecutively.
'a' at fifth position is appearing
2nd time consecutively.
 

Your Task: </br>
You dont need to read input or print anything. Complete the function removeConsecutiveCharacter() which accepts a string as input parameter and returns modified string.
 

Expected Time Complexity: O(|S|). </br>
Expected Auxiliary Space: O(|S|).
 

Constraints: </br>
1<=|S|<=1e5 </br>
All characters are lowercase alphabets.


## Solution : 1
```c++
    // Using unique function
class Solution{
    public:
    string removeConsecutiveCharacter(string s)
    {
        auto last = unique(s.begin(),s.end());
        s.erase(last, s.end());
        return s;
    }
};
```

## Solution 2:
```c++
    // using iteration
class Solution{
    public:
    string removeConsecutiveCharacter(string s)
    {
        string ans = "";
        for (int i = 1; i <= s.size(); i++) {
            if (s[i] != s[i-1]) {
                ans += s[i-1];
            }
        }
        return ans;
    }
};
```

Reference :
- Solution -3 approach is the modifies approach of []


 