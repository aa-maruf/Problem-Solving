## Problem statement:
![D. Odd Queries](/Prefix%20Sum/Assets/D.%20Odd%20Queries.png)

## Problem Link : 
- [D. Odd Queries](https://codeforces.com/contest/1807/problem/D)

## Solution - 
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
              
             ll n,q;
             cin >> n >> q;
             vector<ll> v(n + 1);
             vector<int> pref(n + 1);
             ll cnt = 0;

             for (int i = 1; i <= n; i++) {
                cin >> v[i] ;
                pref[i] = pref[i - 1] + v[i];
             }
            
             for (int i = 1; i <= q; i++) {
                
                ll l,r,k,sum = 0;
                cin >> l >> r >> k;
                sum = k * (r - l + 1) + (pref[n] - (pref[r] - pref[l -1]));

                if (sum & 1) 
                cout << "YES\n";
                else 
                    cout <<"NO\n";

             }  
}
```