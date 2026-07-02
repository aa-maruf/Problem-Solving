Problem link:[Ways to Tile the Floor](https://www.geeksforgeeks.org/problems/count-the-number-of-ways-to-tile-the-floor-of-size-n-x-m-using-1-x-m-size-tiles0509/1)
```python
class Solution:
    dict = {}
    MOD = 10**9 + 7
    def fact (self, n):
        if n in self.dict:
            return self.dict[n]
        res = 1
        for i in range (1, n + 1):
            res *= i
            self.dict[i] = res
        return res  
        
        
        
	def countWays(self, n, m):
		if n <= m:
		    return (1 + (n == m))
		 
		ans = 1
		h = n//m 
		v = n % m
		
		while (h > 0):
		   tiles = h + v
		   comb =  (self.fact (tiles)// (self.fact (h) * self.fact(v))) % self.MOD
		   ans = (ans + comb) % self.MOD
		   h -= 1
		   v += m
		   
		return ans
```