## Problem statement:
Given two arrays A[] and B[] consisting of N and M elements respectively. The task is to find minimum number of elements to remove from each array such that no common element exist in both the arrays.
 

Example 1:

Input :
A[] = { 2, 3, 4, 5, 8 }
B[] = { 1, 2, 3, 4} </br>
Output : </br>
3 </br>
Explanation:</br>
We need to remove 2, 3 and 4 from any 
array.
 

Example 2:

Input :</br>
A[] = { 4, 2, 4, 4}</br>
B[] = { 4, 3 }</br>
Output :</br>
1</br>
Explanation:
We need to remove 4 from B[]
 

Example 3:

Input:</br>
A[] = { 1, 2, 3, 4 }</br>
B[] = { 5, 6, 7 }</br>
Output:
0 </br>
Explanation:</br>
There is no common element in both.
 

Your Task:  
You don't need to read input or print anything. Your task is to complete the function minRemove() which takes the array A[], B[] and its size N, M as inputs and returns the minimum number of elements to be deleted.

 

Expected Time Complexity: O(N)</br>
Expected Auxiliary Space: O(N)</br>

 

Constraints:</br>
1<=N,M<=1e5</br>
1<=A[i],B[i]<=1e5

---

## Solution :
```c++
    class Solution{
    public:
    int minRemove(int a[], int b[], int n, int m) {
        map<int,int> A;
        map<int,int> B;
        for (int i = 0; i < n; i++) {
            A[a[i]]++;
        }
        for (int i = 0; i < m; i++) {
            B[b[i]]++;
        }
        
        int ans = 0;
        for (auto mp : A){
            int x = mp.first;
            if (B.find(x) != B.end())
                ans += min(mp.second, B[x]);
        }
        return ans;
    }
};
```
---

## Problem link:
- [Remove minimum number of elements - GFG(easy)](https://practice.geeksforgeeks.org/problems/remove-minimum-number-of-elements4032/1?utm_source=geeksforgeeks&utm_medium=ml_article_practice_tab&utm_campaign=article_practice_tab)