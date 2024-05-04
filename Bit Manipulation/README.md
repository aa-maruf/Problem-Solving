```c
// Brian kernigham's concept : 
Remove the last set bit :   n & (n-1) 
Power of two : (n & (n-1)) == 0 
// Because Power of two contains only one set bit
```

```c
Find the last set bit: n & (-n)
Remove the last set bit :   n - (n & (n-1))
```

```c
Provide bitwise AND of all numbers from range L to R
        int shiftCnt = 0;
        while(left != right){
            left = left >> 1;
            right = right >> 1;
            shiftCnt++;
        }
        return left << shiftCnt;
    //resource : https://www.youtube.com/watch?v=E0IvvnIMvFk

    /* another approach */
    while (right > left) {
            right = right & (right - 1);
        }
    return right;

    //resource : https://www.youtube.com/watch?v=gLZZyvXTRLk
```


