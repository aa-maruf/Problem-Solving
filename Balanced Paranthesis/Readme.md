# Balanced Parentheses


### Using stack:
Template :
```c++
        stack<int> st;
        for (auto &x : s) {
            if (!st.empty() and st.top() == '[' and x == ']') {
               st.pop();
            } else {
                st.push(x);
            }
        }
         return st.empty();
```

### Using space optimized stack:

```c++
        int unbalanced = 0;
        for (auto &c : s) {
            if (c == '[') {
                unbalanced += 1;
            }
            else {
                if (unbalanced > 0) 
                    unbalanced -= 1;;
            }
        }
        return unbalanced == 0;
```

> Note: This solution will only work when # of opening and closing braces are equal. Here unbalanced is the number of opening bracket. 

### Problems:
- https://leetcode.com/problems/minimum-number-of-swaps-to-make-the-string-balanced/
