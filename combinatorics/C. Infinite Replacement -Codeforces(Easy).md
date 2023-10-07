`Problem type:`
- Easy problem. Need to think about edge case. 
- Time to take (15 - 25 minutes)


## Problem Statement: 
![C. Infinite Replacement](/combinatorics/Assets/C.%20Infinite%20Replacement.png)

## Problem Link:
- [C. Infinite Replacement](https://codeforces.com/contest/1674/problem/C)

## Solution: 
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
              
             string a, b;
             cin >> a >> b;
             int n = a.size();
             int m = b.size();
             int ca = count(a.begin(),a.end(),'a');
             int cb = count(b.begin(),b.end(),'a');

             auto f = [&](int a) -> ll {
                ll ans = 1;
                for (int i = 1; i <= a; i++) {
                    ans *= 2;
                }
                return ans;
             };
             
             if (cb == 0) {

                    ll x = f(ca);
                    cout << x << endl;
             }
              
             else if (b == "a" ) {
                cout << 1 << endl;
             }
             else 
                cout << -1 << endl;
}
```
