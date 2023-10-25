## Points to remember:
- Don't mess up with subset & subarray 😁

## Problem statement:
You are given an array Arr of size N containing non-negative integers. Your task is to choose the minimum number of elements such that their sum should be greater than the sum of the rest of the elements of the array.
```markdown
Example 1:

Input:
N = 4 
Arr[] = {2, 17, 7, 3}
Output:
1
Explanation:
If we only select element 17, the sum of the
rest of the elements will be (2+3+7)=12.
So the answer will be 1.
```

```markdown
Example 2:

Input:
N = 4
Arr = {20, 12, 18, 4}
Output:
2
Explanation:
If we select 12 and 18 from the array,
the sum will be (12+18) = 30 and the sum of
the rest of the elements will be (20+4) = 24.
So, the answer will be 2. We can also
select 20 and 18 as well.
```

Your Task:

You don't need to read input or print anything. Your task is to complete the function minSubset() which takes the array Arr[] and its size N as inputs and returns the minimum number of elements to be selected.

 

Expected Time Complexity: O(N log N)</br>
Expected Auxiliary Space: O(1)

 

Constraints:
1 <= N <= 1e5</br>
1 <= Arr[i] <= 1e9</br>
Array may contain duplicate elements. 



## Solution :
```c++
class Solution{
    public:
    int minSubset(vector<int> arr,int n){
        
        sort(arr.begin(),arr.end(),greater<int>());
        
        long long int total_sum = accumulate(arr.begin(),arr.end(),0ll);
        
        long long int ans = INT_MAX;
        for (long long int i = 0, sum = 0; i < n; i++) {
            sum += arr[i];
            if (sum > (total_sum - sum)) {
                ans = min (ans, i + 1);
                break;
            }
        }
        
        return ans;
    }
};
```


## Problem link :
- [Smallest Subset with Greater Sum - GFG(EASY)](https://practice.geeksforgeeks.org/problems/smallest-subset-with-greater-sum/1?utm_source=geeksforgeeks&utm_medium=ml_article_practice_tab&utm_campaign=article_practice_tab)
