
Problem link: [max-rope-cutting-gfg](https://www.geeksforgeeks.org/problems/max-rope-cutting1312/1)
```python
class Solution:
    def maxProduct(self, n):
        if (n == 2 or n == 3): return n - 1
        mul = 1
        while (n > 4):
            mul *= 3
            n -= 3
        
        
        return mul * n
```