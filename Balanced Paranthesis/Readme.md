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

### [Two pointer :](https://leetcode.com/problems/valid-parenthesis-string/editorial/?envType=daily-question&envId=2024-04-07#approach-4-two-pointer)

```c++
bool checkValidString(string s) {
        int open = 0, close = 0;
        
        for (int i = 0, j = s.size() -1; i < s.size(); i++, j--) {
            if (s[i] == '(') {
                open++;
            } else {
                open--;
            }

            if (s[j] == ')') {
                close++;
            } else {
                close--;
            }

            if (open < 0 or close < 0) return false;
        }

        return true;
    }
```
> Note : this solution will only work for inputs containing only one type of braces. solve problem 4
> if there are multiple braces ([]{()}) then it will not work.
> No. of opening and closing braces doesn't need to be equal.


### [In place modification:](https://leetcode.com/problems/minimum-string-length-after-removing-substrings/editorial/#approach-3-in-place-modification)
```c++
    bool isValid(string s) {
        int readptr, writeptr;
        for (readptr = 1, writeptr = 0; readptr < s.size(); readptr++) {
                // doesn't match
            if (writeptr >= 0 and (s[writeptr] == '(' and s[readptr] == ')' or s[writeptr] == '{' and s[readptr] == '}' or s[writeptr] == '[' and s[readptr] == ']')) {
                writeptr--;
                } else {
                    writeptr++;
                    s[writeptr] = s[readptr];
                }
            }
        return writeptr < 0;
    }
```
>> this work for multiple braces and # of opening & closing brackets doesn't matter.
>> TC (0(n)) and SC (O(1))

### Problems:
- https://leetcode.com/problems/valid-parentheses/
- https://leetcode.com/problems/minimum-string-length-after-removing-substrings/
- https://leetcode.com/problems/minimum-number-of-swaps-to-make-the-string-balanced/
- https://leetcode.com/problems/valid-parenthesis-string/ "two pointer"
  


