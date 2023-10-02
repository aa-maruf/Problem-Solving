## Learning :
- Technique to solve whether sum of subsets == x or not 
- Note: here distinct element k must be between 1 to n.
## Problems Statements:
![C. Vasilije in Cacak](/Codeforces/Assets/C.%20Vasilije%20in%20Cacak.png)

## Problem link :
- [C. Vasilije in Cacak](https://codeforces.com/contest/1878/problem/C)

## Solution : 
```c++
    #include <bits/stdc++.h>
#ifndef ONLINE_JUDGE
    #include "DEBUG.h"
#else
    #define debug(x)
    #define bug(...)
#endif


#define endl  "\n"

using namespace std;

using ll = long long;


void solve() {
              ll n, k, x; cin >> n >> k >> x;

              auto sum = [&](ll n){
                return (n*(n+1)) / 2;
              };
              
              ll minSum = sum (k);
              ll maxSum = sum (n) - sum(n-k);

              if (x >= minSum && x <= maxSum)
                cout <<"YES\n";
              else 
                cout << "NO\n";
}
```