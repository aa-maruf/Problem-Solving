>An axis-aligned rectangle is represented as a list [x1, y1, x2, y2], where (x1, y1) is the coordinate of its bottom-left corner, and (x2, y2) is the coordinate of its top-right corner. Its top and bottom edges are parallel to the X-axis, and its left and right edges are parallel to the Y-axis.

>`Two rectangles overlap if the area of their intersection is positive.` To be clear, two rectangles that only touch at the corner or edges do not overlap.

>Given two axis-aligned rectangles rec1 and rec2, return true if they overlap, otherwise return false.

 

Example 1:

Input: rec1 = [0,0,2,2], rec2 = [1,1,3,3]</br>
Output: true </br>
Example 2:

Input: rec1 = [0,0,1,1], rec2 = [1,0,2,1]</br>
Output: false</br>
Example 3:

Input: rec1 = [0,0,1,1], rec2 = [2,2,3,3]</br>
Output: false
 

Constraints:

rec1.length == 4</br>
rec2.length == 4</br>
-1e9 <= rec1[i], rec2[i] <= 1e9</br>
rec1 and rec2 represent a valid rectangle with a non-zero area.

---

## Solution - 1
```c++
// Solution - 2 better solution
/// This line the key line - "Two rectangles overlap if the area of their intersection is positive."
class Solution {
public:
    bool isRectangleOverlap(vector<int>& rect1, vector<int>& rect2) {
        // auto [ax1, ay1, ax2, ay2] = rect1;
        // auto [bx1, by1, bx2, by2] = rect2;
        long long ax1 = rect1[0],ay1 = rect1[1],ax2 = rect1[2],ay2 = rect1[3];
        long long bx1 = rect2[0],by1 = rect2[1],bx2 = rect2[2],by2 = rect2[3];
        
        long long weight = min(ax2, bx2) - max (ax1, bx1);
        long long height = min (ay2, by2) - max (ay1, by1);
        
         return height > 0 and weight > 0; 
    }
};

```
---

Problem links:
- [836. Rectangle Overlap- leetcode easy](https://leetcode.com/problems/rectangle-overlap/)
- [Overlapping sheets - atcoder](https://atcoder.jp/contests/abc318/tasks/abc318_b)
- [Rectangle area - leetcode Medium](https://leetcode.com/problems/rectangle-area/description/)