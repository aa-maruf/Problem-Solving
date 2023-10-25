
## Things to ask
* whether the array contains negative value or not.
* if positive, whether K or the target can be 0 not.
* if k can be then we have handle this in the if condition i >= y


## Problem statement:
Given an unsorted array A of size N that contains only positive integers, find a continuous sub-array that adds to a given number S and return the left and right index(1-based indexing) of that subarray.

In case of multiple subarrays, return the subarray indexes which come first on moving from left to right.

Note:- You have to return an ArrayList consisting of two elements left and right. In case no such subarray exists return an array consisting of element -1.</br>

Example 1: 

Input:</br>
N = 5, S = 12
A[] = {1,2,3,7,5} </br>
Output: 2 4 </br>
Explanation: The sum of elements 
from 2nd position to 4th position 
is 12.
Example 2:

Input:
N = 10, S = 15

A[] = {1,2,3,4,5,6,7,8,9,10}

Output: 1 5

Explanation: The sum of elements 
from 1st position to 5th position
is 15.

Your Task:
You don't need to read input or print anything. The task is to complete the function subarraySum() which takes arr, N, and S as input parameters and returns an ArrayList containing the starting and ending positions of the first such occurring subarray from the left where sum equals to S. The two indexes in the array should be according to 1-based indexing. If no such subarray is found, return an array consisting of only one element that is -1.

Expected Time Complexity: O(N)

Expected Auxiliary Space: O(1)

Constraints:</br>
`1 <= N <= 1e5`</br>
`0 <= Ai <= 1e9` </br>
`0<= S <= 1e9`

---

## Solution :
```c++
#include <bits/stdc++.h>
using namespace std;

class Solution
{
    public:
    vector<int> subarraySum(vector<int>arr, int n, long long s)
    {
        long long  j = 0;
        for (long long i = 0, sum = 0 ; i < n; i++ ) {
            sum += arr[i];
            while (sum > s) {
                sum -= arr[j];
                j++;
            }
            if (sum == s && i >= j) {
                return {j + 1, i + 1};
            }    
        }
        return {-1};
    }
};

/**
 * test case 1:
5 12
1 2 3 7 5
* test case 2:
5 0
1 2 3 7 5

*/
```
---
Problem Link:
- [Subarray with given sum](https://practice.geeksforgeeks.org/problems/subarray-with-given-sum-1587115621/1?utm_source=geeksforgeeks&utm_medium=ml_article_practice_tab&utm_campaign=article_practice_tab)