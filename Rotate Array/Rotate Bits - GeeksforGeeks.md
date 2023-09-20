# Problem Statement:
Given an integer N and an integer D, rotate the binary representation of the integer N by D digits to the left as well as right and return the results in their decimal representation after each of the rotation.</br>
Note: Integer N is stored using 16 bits. i.e. 12 will be stored as 0000000000001100.

Example 1:

Input:</br>
N = 28, D = 2 </br>
Output:</br>
112</br>
7</br>
Explanation: </br>
28 in Binary is: 0000000000011100 </br>
Rotating left by 2 positions, it becomes 0000000001110000 = 112 (in decimal). </br>
Rotating right by 2 positions, it becomes 0000000000000111 = 7 (in decimal). </br>
Example 2:

Input: </br>
N = 29, D = 2</br>
Output: </br>
116</br>
16391</br>
Explanation: </br>
29 in Binary is: 0000000000011101</br>
Rotating left by 2 positions, it becomes 0000000001110100 = 116 (in decimal).</br>
Rotating right by 2 positions, it becomes 100000000000111 = 16391 (in decimal).

Extra test case :
10 8  </br>
28 2 </br>
29 2 </br>
8426 12464 </br>
output :  </br>
2560 2560 </br>
112 7 </br>
116 16391 </br>
8426 8426

---

### Solution - 01 
```c++
    class Solution
{
  public:
        vector <int> rotate (int n, int d)
        {
            d = d % 16;
            int temp = n;
            vector<int>v(16);
            
            for (int i = 15; i >= 0; i--) {
                    v[i] = (temp & 1);
                    temp >>= 1; 
            }
            
            int idx = (16 - d) % 16;
            vector<int> r(16);
            
            for (int i = 0; i < 16; i++) {
                r[i] = v[idx];
                idx++;
                if (idx >= 16)
                    idx = idx % 16;
            }
            
            vector<int> l(16);
            idx = d;
            
            for (int i = 0; i < 16; i++) {
                l[i] = v[idx];
                idx++;
                if (idx >= 16)
                    idx = idx % 16;
            }
            
            int left = 0, right = 0, j= 15;
            
            for (int i = 0; i< 16; i++) {
                left += (l[i] << j);
                right += (r[i] << j);
                j--;
            }

            v.clear();
            l.clear();
            r.clear();
            return  {left, right};
        }
};

```

---
### Problem link: 
- [Rotate Bits - GFG Easy](https://practice.geeksforgeeks.org/problems/rotate-bits4524/1?utm_source=youtube&utm_medium=courseteam_practice_desc&utm_campaign=problem_of_the_day)