
Article link: [Ways to Express as Sum of Consecutives](https://www.geeksforgeeks.org/dsa/count-ways-express-number-sum-consecutive-numbers/)
```python
class Solution:
    def getCount(self, n):
        ans = 0
        
        k = 2
        
        while (True):
            baseSum = k * (k - 1)/ 2
            if (baseSum >= n): break
            
            ans += ((n - baseSum) % k) == 0;
            
            k += 1
            
        return ans
```
