problem link : [Max Product Subset - GeeksforGeeks](https://www.geeksforgeeks.org/problems/maximum-product-subset-of-an-array/1)

```python
class Solution:
    def findMaxProduct(self, arr):
        n = len (arr)
        MOD = 10**9 + 7
        
        mul, mx_neg, total_zeros, total_neg, idx_mx_neg = 1, -100, 0, 0, -1
        
        for i in range (n):
            if (arr[i] < 0):
                total_neg += 1
                if (mx_neg <= arr[i]):
                    mx_neg = arr[i];
                    idx_mx_neg = i;
            
            elif (arr[i] == 0):
                total_zeros += 1
        
        
        
        if (total_neg == 1):
            if (total_zeros and total_zeros == n - 1):
                return 0
            elif (n == 1):
                return arr[0]
        
        if (total_zeros == n): return 0;
        
        for i in range (n):
            if (arr[i] == 0 or (total_neg % 2 == 1 and idx_mx_neg == i)):   
                continue
            mul = ((mul * arr[i]) % MOD + MOD) % MOD
            # print (arr[i], mul, total_neg)
            
            
        return mul
```