## Prorblem statement:
Given an array of positive and negative numbers. Find if there is a subarray (of size at-least one) with 0 sum.
```markdown
Example 1:

Input:
5
4 2 -3 1 6

Output: 
Yes

Explanation: 
2, -3, 1 is the subarray 
with sum 0.
```

```markdown
Example 2:

Input:
5
4 2 0 1 6

Output: 
Yes

Explanation: 
0 is one of the element 
in the array so there exist a 
subarray with sum 0.
```
Your Task:

You only need to complete the function subArrayExists() that takes array and n as parameters and returns true or false depending upon whether there is a subarray present with 0-sum or not. Printing will be taken care by the drivers code.

Expected Time Complexity: O(n).</br>
Expected Auxiliary Space: O(n).

Constraints: </br>
1 <= n <= 1e4 </br>
-1e5 <= a[i] <= 1e5

## Solution:
```c++
class Solution{
    public:
    bool subArrayExists(int arr[], int n)
    {
        unordered_map<int,bool> m; // got error for only map (use umap).gives 0(1)
        for (int i = 0,sum = 0; i < n; i++){
            sum += arr[i];
            if (sum == 0)
                return true;
            int k = sum;
            if (m.find(k) != m.end())
                return true;
                
            if (m.find(sum) == m.end())
                m[sum] = true;
        }
        return false;
    }
};
```

```c++
// shorter version of prev code.
class Solution{
    public:
    bool subArrayExists(int arr[], int n)
    {
        unordered_map<int,bool> m; // got error for only map (use umap).gives 0(1)
        for (int i = 0,sum = 0; i < n; i++){
            sum += arr[i];
            if (sum == 0 || m.find(sum) != m.end())
                return true;
                
            m[sum] = true;
        }
        return false;
    }
};
```
## Problem link:
- [Subarray with 0 sum](https://practice.geeksforgeeks.org/problems/subarray-with-0-sum-1587115621/1)