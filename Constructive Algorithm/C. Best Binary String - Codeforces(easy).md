## Problem Statement :
![C. Best Binary String](/Constructive%20Algorithm/Assets/C.%20Best%20Binary%20String.png)

## Problem link:
[C. Best Binary String](https://codeforces.com/contest/1837/problem/C)

## Solution - 1:

```c++
#include <bits/stdc++.h>

#define endl  "\n"

using namespace std;

using ll = long long;

void solve() {
       string s;
       cin >> s;

     char z = '1';

    for (int i = s.size() -1; i >= 0; i--) {
            if (s[i] == '?')
                s[i] = z;

            z = s[i];
      }

      cout << s << endl; 
}
```

