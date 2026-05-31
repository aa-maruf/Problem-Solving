# B - Two Rings

## Problem Statement

Given two circles with centers at (x₁, y₁) and (x₂, y₂) with radii r₁ and r₂, determine if the two circles intersect or touch each other.

**Problem Link:** [AtCoder - ABC460 B - Two Rings](https://atcoder.jp/contests/abc460/tasks/abc460_b)

---

## Problem Description

Two circles are considered to "intersect or touch" if they have at least one point in common. This includes:
- Circles intersecting at two points
- Circles touching externally at one point
- Circles touching internally at one point
- One circle completely inside the other

---

## Key Insights & Logic

### The Core Inequality

The criterion for two circles to have at least one common point is:

```
|r₁ - r₂| ≤ d ≤ r₁ + r₂
```

Where:
- `d` = distance between centers
- `r₁, r₂` = radii of the two circles

---

### Understanding Each Case

Based on the distance `d` between centers, there are five possible scenarios:

1. **External Tangent** (touching externally)
   - Condition: `d = r₁ + r₂`
   - The circles touch at exactly one point on the outside
   - Example: Two circles next to each other, kissing

2. **Internal Tangent** (touching internally)
   - Condition: `d = |r₁ - r₂|`
   - The circles touch at exactly one point on the inside
   - Example: Smaller circle inside larger circle, touching at one point

3. **Two Intersection Points**
   - Condition: `|r₁ - r₂| < d < r₁ + r₂`
   - The circles intersect at exactly two points
   - Example: Two overlapping circles

4. **No Intersection** (one inside other)
   - Condition: `d < |r₁ - r₂|`
   - One circle lies completely inside the other
   - No common points

5. **No Intersection** (too far apart)
   - Condition: `d > r₁ + r₂`
   - Circles are too far apart to touch
   - No common points

---

### Why Use Squared Distance?

To avoid floating-point precision issues with square roots, we work with squared distances:
- `d² = (x₁ - x₂)² + (y₁ - y₂)²`
- Check: `(r₁ - r₂)² ≤ d² ≤ (r₁ + r₂)²`

---

## Solution

```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;

    while (t--) {
        long long x1, y1, r1, x2, y2, r2;
        cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;

        // Calculate squared distance between centers
        long long dx = x1 - x2;
        long long dy = y1 - y2;
        long long d_squared = dx * dx + dy * dy;

        // Calculate sum and difference of radii
        long long sum = r1 + r2;
        long long diff = abs(r1 - r2);

        // Check if circles intersect or touch
        if (diff * diff <= d_squared && d_squared <= sum * sum) {
            cout << "Yes\n";
        } else {
            cout << "No\n";
        }
    }

    return 0;
}
```

---

## Complexity Analysis

### Time Complexity
- **O(t)** - Where t is the number of test cases, each test case is O(1)

### Space Complexity
- **O(1)** - Only using constant extra space for variables

---

## Examples

### Example 1: Intersecting Circles
```
Input:
x₁=0, y₁=0, r₁=5
x₂=3, y₂=4, r₂=3

d² = 3² + 4² = 25
sum = 5 + 3 = 8, sum² = 64
diff = |5 - 3| = 2, diff² = 4

Check: 4 ≤ 25 ≤ 64 ✓
Output: Yes
```

### Example 2: Separate Circles
```
Input:
x₁=0, y₁=0, r₁=2
x₂=10, y₂=10, r₂=2

d² = 10² + 10² = 200
sum = 2 + 2 = 4, sum² = 16
diff = |2 - 2| = 0, diff² = 0

Check: 0 ≤ 200 ≤ 16 ✗
Output: No
```

### Example 3: Internally Tangent (Touching Inside)
```
Input:
x₁=0, y₁=0, r₁=5
x₂=2, y₂=0, r₂=2

d² = 2² = 4
sum = 5 + 2 = 7, sum² = 49
diff = |5 - 2| = 3, diff² = 9

Check: 9 ≤ 4 ≤ 49 ✗
Output: No (one circle is inside another without touching)
```

---

## Key Concepts

- **Circle Geometry** - Distance formula, circle intersection conditions
- **Squared Distance** - Avoids floating point precision issues
- **Case Analysis** - Understanding different intersection scenarios

---

## Why Squared Distance?

Working with squared distances avoids:
- Floating point precision errors from square root operations
- Performance overhead of computing square roots
- Potential rounding errors affecting accuracy

