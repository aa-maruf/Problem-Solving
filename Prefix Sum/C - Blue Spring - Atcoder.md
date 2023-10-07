## Problem Statement</br>
Takahashi is planning an 
N-day train trip.
For each day, he can pay the regular fare or use a one-day pass.

Here, for 
1≤i≤N, the regular fare for the 
i-th day of the trip is 
F<sub>i</sub> yen.
On the other hand, a batch of 
D one-day passes is sold for 
P yen. You can buy as many passes as you want, but only in units of 
D.
Each purchased pass can be used on any day, and it is fine to have some leftovers at the end of the trip.

Find the minimum possible total cost for the 
N-day trip, that is, the cost of purchasing one-day passes plus the total regular fare for the days not covered by one-day passes.

Constraints </br>
1≤N≤2×10 <sup>5</sup>

1≤D≤2×10<sup>5</sup>

 
1≤P≤10<sup>9</sup> and 1≤F<sub>i</sub> ≤10<sup>9</sup> 

 
All input values are integers.</br>
Input</br>
The input is given from Standard Input in the following format:

N D P</br>
F<sub>1</sub> F<sub>2</sub>  … F<sub>N</sub>

​
 
Output</br>
Print the minimum possible total cost for the 
N-day trip.

## Solution - 1 (prefix sum) :

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
     long long int n, d, p, sum = 0, ans = 0; cin >> n >> d >> p;
     vector <long long int> v (n);
     vector <long long int> prefix_sum(n);

     for (int i = 0; i < n; i++) {
        cin >> v[i]; 
     }
     
     sort (v.begin(), v.end(),greater<long long int>());
     partial_sum(v.begin(),v.end(),prefix_sum.begin());
     bool f  = false;

     for (int i = d - 1; f != true; i += d) {

        if (i >= n ) {
            f |= 1;
            ans += (prefix_sum[n-1] - sum) > p ? p : (prefix_sum[n-1] - sum);
            
        }
        else {
            ans += (prefix_sum[i] - sum) > p ? p : (prefix_sum[i] - sum);
            sum = prefix_sum[i];
        }

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
    /// CODE-------------

    int t = 1;
    //cin >> t;

    while (t--) {
        solve();
    }

    cerr << endl << "Run Time : " << ((double)(clock() - z) / CLOCKS_PER_SEC);

    return 0;
}

```

# Solution - 2 (Using multiset) :
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
    long long int n, d, p, sum , ans, x = 0; cin >> n >> d >> p;
     vector <long long int> v (n);
     multiset<long long int> mst;
     for (auto &x : v) {
        cin >> x;
        mst.insert(x);
    }

     ans = sum = accumulate (v.begin(),v.end(),0LL);

     while (x < n) {
        x += d;
        sum += p;              // pass er price add krbo
        for (int i = 0; i < d && mst.size(); i++) {   /// 4 ta pass er value erase krbo decresing order e
            sum -= *(mst.rbegin());
            mst.erase(--mst.end());
        } 
        ans = min (ans, sum);
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
    /// CODE-------------

    int t = 1;
    //cin >> t;

    while (t--) {
        solve();
    }

    cerr << endl << "Run Time : " << ((double)(clock() - z) / CLOCKS_PER_SEC);

    return 0;
}
```
---
Problem links :
- [C - Blue Spring - Atcoder](https://atcoder.jp/contests/abc318/tasks/abc318_c)