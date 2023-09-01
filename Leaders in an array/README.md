>Given an array A of positive integers. Your task is to find the leaders in the array. An element of array is leader if it is greater than or equal to all the elements to its right side. The rightmost element is always a leader. 

`Example 1:`

Input: </br>
n = 6 </br>
A[] = {16,17,4,3,5,2} </br>
Output: 17 5 2 </br>
Explanation: The first leader is 17 
as it is greater than all the elements
to its right.  Similarly, the next 
leader is 5. The right most element 
is always a leader so it is also 
included. </br>
Example 2:

Input:</br>
n = 5</br>
A[] = {1,2,3,4,0}</br>
Output: 4 0</br>
Explanation: 0 is the rightmost element
and 4 is the only element which is greater
than all the elements to its right.</br>
Your Task:
You don't need to read input or print anything. The task is to complete the function leader() which takes array A and n as input parameters and returns an array of leaders in order of their appearance.

Expected Time Complexity: O(n) </br>
Expected Auxiliary Space: O(n)

Constraints:</br>
1 <= n <= 1e7 </br>
0 <= Ai <= 1e7 </br>

## Solution - 1
```c++
    class Solution{
    public:
    vector<int> leaders(int a[], int n){
        int mx = -1;
        vector<int> ans;
        for (int i = n -1 ; i >= 0; i--){
            if (a[i] >= mx)
                ans.push_back(a[i]);
            mx = max (a[i],mx);
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
```
---
problems Link : [Leaders in an array - GFG EASY](https://practice.geeksforgeeks.org/problems/leaders-in-an-array-1587115620/0)

Explanation : [GFG youtube](https://youtu.be/jDPrM5XIqzM?si=sqBRY2hnQyw8lbtE)