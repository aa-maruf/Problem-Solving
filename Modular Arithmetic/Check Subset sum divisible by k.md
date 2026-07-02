#### Problem Link : [Check Subset sum divisible by k -GeeksofrGeeks](https://www.geeksforgeeks.org/problems/subset-with-sum-divisible-by-m2546/1)


#### Prerequite:
- DP + Memorization
- [974. Subarray Sums Divisible by K - Leetcode](https://leetcode.com/problems/subarray-sums-divisible-by-k/description/)

```c++
class Solution {
  public:
    bool solve (vector<int>& arr, int k, int idx, int currSum, int cnt, vector<vector<int>>& vis) {
        if (idx == arr.size()) {
            if (cnt and currSum % k == 0) 
                return true;
            else 
                return false;
        }
        
        if (vis[idx][currSum] != -1) return vis[idx][currSum];
        return vis[idx][currSum] = solve (arr, k, idx + 1, (currSum + arr[idx]) % k, cnt + 1, vis) or solve (arr, k, idx + 1, currSum, cnt, vis);
    }
    
    
    bool divisibleByK(vector<int>& arr, int k) {
       int n = arr.size();
       int sum = 0;
    //   for (int i = 0; i < n; i++) sum += arr[i];
       vector<vector<int>> vis (n + 1, vector<int>(k + 1, -1)); 
       return solve (arr, k, 0, 0, 0, vis);
    }
};
```


