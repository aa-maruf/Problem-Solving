## Learning:
- Used multiset here and learned how to use it optimally.
- The use of turn varible for swapping element was new thing to learn.

## Problem Statement :
![B. Jellyfish and Game](/Codeforces/Assets/image.png)

### Problem link:
- [B. Jellyfish and Game](https://codeforces.com/problemset/problem/1875/B)


### Solution -

```c++
#include <bits/stdc++.h>
using namespace std;


#ifndef ONLINE_JUDGE
    #include "DEBUG.h"
#else
    #define debug(x)
    #define bug(...)
#endif


#define endl  "\n"



using ll = long long;


void solve() {
              
             ll n,m,k;
             cin >> n >> m >> k;
             vector<multiset<ll>>s(2);

            for (int j = 0; j < n; j++) {
                ll x; cin >> x;
                s[0].insert(x);
            }
            for (int j = 0; j < m; j++) {
                ll x; cin >> x;
                s[1].insert(x);
            }

            ll mn = min(*s[0].begin(), *s[1].begin());
            ll mx = max (*s[0].rbegin(), *s[1].rbegin());
            
            int turn = 0;
            while (k) {
                ll small = *(s[turn].begin());
                ll big = *(s[turn^1].rbegin());

                if (small == mn && big == mx) {
                    k = k & 1; // k = k % 2
                    if (k == 0)  break;
                }

                if (small < big) {
                    s[turn].erase (s[turn].find(small));
                    s[turn ^ 1].erase (s[turn^1].find(big));
                    s[turn].insert (big);
                    s[turn ^ 1].insert (small);
                }

                k--;
                turn ^= 1;
            }
        
            ll ans = 0; 
            for (auto x : s[0])  {
                ans += x; 
            }
            cout << ans << endl;      
}


int main() {

    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    #ifndef ONLINE_JUDGE
    freopen("Error.txt", "w", stderr);
    #endif

    clock_t z = clock();
    

    int t = 1;
    cin >> t;

    while (t--) {
        solve();
    }

    cerr << endl << "Run Time : " << ((double)(clock() - z) / CLOCKS_PER_SEC);

    return 0;
}

```

## Resource :
- [TLE Youtube ](https://youtu.be/kCcaHeVFkoI?si=Y5cd78YPzUn1dApW&t=316)