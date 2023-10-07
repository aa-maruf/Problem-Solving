## Problem Statement:
![B. Optimal Reduction](/Constructive%20Algorithm/Assets/B.%20Optimal%20Reduction%20-Codeforces.png)

## Resources:
[Wrong submission](https://www.youtube.com/watch?v=Q-GFpOCTz0c&t=481s)

## Solution :
```c++
 #include <bits/stdc++.h>

#define endl  "\n"

using namespace std;

using ll = long long;

void solve() {
              
       ll n; 
       cin >> n;
       vector<ll>v(n);
       ll mx = 0;
       ll pos = 0;
       bool ans = true;
       for (int i = 0; i < n; i++) {
          cin >> v[i];

          if (v[i] > mx ) {
            mx = v[i];
            pos = i;
          }
       }
       int i;
       for (i = 0; i < pos; i++) {
            if (v[i] > v[i+1]) {
                cout << "NO\n";
                return;
            }
       }

       for ( ;i < n - 1; i++) {
            if (v[i] < v[i+1]) {
                cout << "NO\n";
                return;
            }
       }

       cout << "YES\n";     
}

```