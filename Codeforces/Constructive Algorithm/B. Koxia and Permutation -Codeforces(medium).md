## Problem Statement:
![B. Koxia and Permutation](/codeforces/Constructive%20Algorithm/Assets/B.%20Koxia%20and%20Permutation.png)

## Problem link:
[B. Koxia and Permutation](https://codeforces.com/problemset/problem/1770/B)

## Solution -1 :
```c++
#include <bits/stdc++.h>

#define endl  "\n"

using namespace std;

using ll = long long;

void solve() {
       ll n,k; cin >> n >> k; 
        

        vector<ll> cnt(n);
        vector<ll> ans(n);


        int value = n;
        for (auto &x : cnt) x = value--;

        int j = 0, l = 1;


        for (int i = 0; i < n; i++) {
            if (i % 2 != 1)
               ans [i] = cnt[j++];
            else 
                 ans[i] = l++;
        }

        for (auto x : ans) cout << x << " "; cout << endl;

}

```

## Solution -2 
```c++
// First solution I made.
#include <bits/stdc++.h>

#define endl  "\n"

using namespace std;

using ll = long long;

void solve() {
       ll n,k; cin >> n >> k; 
    
        vector<ll> cnt(n);
        vector<ll> ans(n);

        int value = n;
        for (auto &x : cnt) x = value--;

        int j = 0, l = 1;

        for (int i = 0; i < n; i++) {
            if (i % k != (k-1))
               ans [i] = cnt[j++];
            else 
                 ans[i] = l++;
        }

        for (auto x : ans) cout << x << " " ; cout << endl;
}
```