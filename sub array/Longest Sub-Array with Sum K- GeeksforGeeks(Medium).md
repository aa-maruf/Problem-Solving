## Problem Statement:
Given an array containing N integers and an integer K. Your task is to find the length of the longest Sub-Array with the sum of the elements equal to the given value K.

 
```markdown
Example 1:
 
Input :
A[] = {10, 5, 2, 7, 1, 9}
K = 15
Output : 4
Explanation:
The sub-array is {5, 2, 7, 1}.
```

```markdown
Example 2:

Input :  
A[] = {-1, 2, 3} 
K = 6 
Output : 0 
Explanation:
There is no such sub-array with sum 6.
```

Your Task:</br>
This is a function problem. The input is already taken care of by the driver code. You only need to complete the function lenOfLongSubarr() that takes an array (A), sizeOfArray (n),  sum (K)and returns the required length of the longest Sub-Array. The driver code takes care of the printing.

Expected Time Complexity: O(N).</br>
Expected Auxiliary Space: O(N).

 

Constraints: </br>
1<=N<=1e5,</br>
-1e5<=A[i], K<=1e5 

## Solution :
```c++
    class Solution{
    public:
    int lenOfLongSubarr(int a[],  int n, int k) 
    { 
        vector<int>prefix(n);
        map<int,int>m;
        int ans = 0;
        partial_sum(a,a+n,prefix.begin());
        for (int i = 0; i < n; i++) {
            if (prefix[i] == k)
                ans = max (ans,i + 1);
                
            int x = prefix[i] - k;
            
            if (m.find(x) != m.end()) 
                ans = max (ans, i - m[x]);
            
            if (m.find(prefix[i]) == m.end()){
                m[prefix[i]] = i;
            }
        }
        return ans;
    }
};
```

## Problem link:
- [Longest Sub-Array with Sum K- GeeksforGeeks(Medium)](https://practice.geeksforgeeks.org/problems/longest-sub-array-with-sum-k0809/0)