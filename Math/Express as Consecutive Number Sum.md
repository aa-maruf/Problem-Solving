# Express as Consecutive Number Sum

## Problem Statement

Given a positive integer `n`, determine if it can be expressed as a sum of consecutive integers (two or more consecutive numbers).

**Problem Link:** [GeeksforGeeks - Consecutive Numbers for Sum](https://www.geeksforgeeks.org/problems/consecutive-numbers-for-sum3132/1)

---

## Problem Description

A number can be expressed as a sum of consecutive integers in multiple ways. For example:
- 15 = 7 + 8 = 4 + 5 + 6 = 1 + 2 + 3 + 4 + 5
- 5 = 2 + 3
- Some numbers cannot be expressed this way (e.g., powers of 2)

---

## Key Insights & Logic

### Mathematical Approach

For a sequence of `k` consecutive integers starting from `a`:
```
a + (a+1) + (a+2) + ... + (a+k-1) = n
```

This simplifies to:
```
k*a + (0 + 1 + 2 + ... + (k-1)) = n
k*a + k*(k-1)/2 = n
```

Solving for `a`:
```
a = (n - base) / k, where base = k*(k-1)/2
```

For a valid sequence:
1. `base < n` (otherwise the arithmetic series sum exceeds n)
2. `(n - base) % k == 0` (a must be a positive integer)
3. `a >= 1` (starting number must be positive)

### Algorithm

- Iterate through all possible values of `k` (starting from k=2)
- For each k, calculate `base = k*(k-1)/2`
- Check if `(n - base)` is divisible by `k`
- Stop when `base >= n`

---

## Solution

```cpp
class Solution {
  public:
    bool isSumOfConsecutive(int n) {
        long long k = 2;
        
        while (true) {
            long long base = (k * (k - 1)) / 2;
            
            // If base exceeds n, no valid sequence exists
            if (base >= n) 
                return false;
            
            // Check if (n - base) is divisible by k
            if ((n - base) % k == 0) 
                return true;
            
            k++;
        }
        
        return false;
    }
};
```

---

## Complexity Analysis

### Time Complexity
- **O(√n)** - We iterate k from 2 until k*(k-1)/2 >= n, which happens when k ≈ √(2n)

### Space Complexity
- **O(1)** - Only using constant extra space

---

## Examples

### Example 1:
```
Input: n = 15
Output: true
Explanation: 15 = 7 + 8 = 4 + 5 + 6 = 1 + 2 + 3 + 4 + 5
```

### Example 2:
```
Input: n = 5
Output: true
Explanation: 5 = 2 + 3
```

### Example 3:
```
Input: n = 8
Output: false
Explanation: 8 is a power of 2, cannot be expressed as consecutive sum
```

---

## Related Concepts

- **Arithmetic Series Sum Formula**
- **Number Theory** - Divisibility and modular arithmetic
- **Consecutive Sequences**

