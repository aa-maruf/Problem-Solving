## Learning:
- In constuctive algo problem, if the question asks you too form an array, then always search for a value as array element and then work with that to get other values of that array.

## Problems Statement:
![B. Beautiful Array](/Constructive%20Algorithm/Assets/B.%20Beautiful%20Array%20-Codeforces.png)

## Problem link :
[B. Beautiful Array](https://codeforces.com/problemset/problem/1715/B)

## Resources :
- [algo bot youtube](https://www.youtube.com/watch?v=4IEAyZtWbe4)

## Solution -1 :
```c++
/// Easy to understand
#include <bits/stdc++.h>

#define endl  "\n"

using namespace std;

using ll = long long;

void solve() {
              
        ll n, k, b, s;
        cin >> n >> k >> b >> s;

        vector<ll> ans (n);

        if (s/k < b) {
            cout << -1 << endl;
            return;
        }

        else {
             ll lastValue = min(s, b*k+ k -1);
             if (s - lastValue > (n-1)*(k-1)) {
                cout << -1 << endl;
                return ;
             }

             ans[0] = lastValue;
             s -= lastValue;
             for (int i = 1; i < n; i++) {
                 ans[i] = min(s, k-1);
                 s -= min(s, k-1);
             }
        }

        for (auto x : ans) 
            cout << x << " " ; cout << endl;
    
}
```

## Solution - 2:
```c++
/// Hard solution. Difficult to understand. Jiangly's solve.
#include <bits/stdc++.h>

using i64 = long long;

void solve() {
    int n, k, b;
    i64 s;
    std::cin >> n >> k >> b >> s;
    
    i64 cur = s / k;
    if (b > cur) {
        std::cout << "-1\n";
        return;
    }
    
    std::vector<i64> a(n);
    a[0] = s;
    
    for (int i = 1; i < n; i++) {
        if (cur > b && a[0] >= k) {
            cur -= (a[0] % k != k - 1);  /// how this works?
            a[0] -= k - 1;
            a[i] = k - 1;
        }
    }
    
    if (cur != b) {
        std::cout << "-1\n";
        return;
    }
    for (int i = 0; i < n; i++) {
        std::cout << a[i] << " \n"[i == n - 1];
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int t;
    std::cin >> t;
    
    while (t--) {
        solve();
    }
    
    return 0;
}
```