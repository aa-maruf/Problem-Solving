## Problem Statement</br>
There are 
N rectangular sheets spread out on a coordinate plane.

Each side of the rectangular region covered by each sheet is parallel to the 
x- or 
y-axis.
Specifically, the 
i-th sheet covers exactly the region satisfying 
A<sub>i</sub>≤x≤B<sub>i</sub> and C<sub>i</sub> ≤y≤D<sub>i</sub> .

Let S be the area of the region covered by one or more sheets. It can be proved that S is an integer under the constraints.</br>
Print S as an integer.

Constraints </br>
2≤N≤100 </br>
0≤A<sub>i</sub> < B <sub>i</sub> ≤100 and 0≤C<sub>i</sub>< D<sub>i</sub> ≤100 </br>

All input values are integers.

Sample Input 1
3
0 5 1 3
1 4 0 5
2 5 2 4
Sample Output 1
20


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
    int n; cin >> n;
    vector < array < int, 4>> va(n);
    for (auto &[a, b, c, d] : va) {
        cin >> a >> b >> c >> d;
    }
    int ans = 0;
    for (int i = 0; i <= 100; i++) {
        for (int j = 0; j <= 100; j++) {
            int f = 0;
            for (auto [a, b, c, d] : va) {
                f |= (i >= a && i< b && j >=c && j < d);
            }
            ans += f;
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
---

Problem Link: </br>
[B - Overlapping sheets - Atcoder](https://atcoder.jp/contests/abc318/tasks/abc318_b)
