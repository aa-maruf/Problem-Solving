## Problem Statement:
Must try problem for practiciong nested map.

---

## C. Beautiful Triple Pairs[^1^][1]

**Time limit per test:** 4 seconds  
**Memory limit per test:** 256 megabytes

Polycarp was given an array `a` of `n` integers[^4^][4]. He really likes triples of numbers, so for each `j` (1 ≤ j ≤ n - 2) he wrote down a triple of elements `[a_j, a_{j+1}, a_{j+2}]`.

Polycarp considers a pair of triples `b` and `c` beautiful if they differ in exactly one position, that is, one of the following conditions is satisfied:[^6^][6]
- `b_1 ≠ c_1` and `b_2 = c_2` and `b_3 = c_3`;
- `b_1 = c_1` and `b_2 ≠ c_2` and `b_3 = c_3`;
- `b_1 = c_1` and `b_2 = c_2` and `b_3 ≠ c_3`.

Find the number of beautiful pairs of triples among the written triples `[a_j, a_{j+1}, a_{j+2}]`.

### Input

The first line contains a single integer `t` (1 ≤ t ≤ 10^4) — the number of test cases[^8^][8][^9^][9].

The first line of each test case contains a single integer `n` (3 ≤ n ≤ 2 ⋅ 10^5) — the length of the array `a`.

The second line of each test case contains `n` integers `a_1, a_2, …, a_n` (1 ≤ a_i ≤ 10^6) — the elements of the array.

It is guaranteed that the sum of the values of `n` for all test cases in the test does not exceed 2 ⋅ 10^5.

### Output

For each test case, output a single integer — the number of beautiful pairs of triples among the pairs of the form `[a_j, a_{j+1}, a_{j+2}]`.

Note that the answer may not fit into 32-bit data types.



## Solutions: 
```c++
#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
    int t = 1, tc;
    cin >> t;

    auto solve = [&] () -> void {
        int n; cin >> n;

        vector<int> v(n);
        for (auto &x : v) cin >> x;

        map <pair<int, int> , map<int, int>> mx, my, mz;
        map <pair<int, int>, int> cx, cy, cz;

        ll ans = 0;

        for (int i = 0; i < n - 2; i++) {
            int x, y, z;
            x = v[i];
            y = v[i+1];
            z = v[i+2];

            // for x differ
            pair<int, int> p = {y, z};
            ans += cx[p]        ;
            if (mx[p].find(x) != mx[p].end()) {
                ans -= mx[p][x];
            }
            mx[p][x] += 1;
            cx[p] += 1;


            // for y differ
            p = {x, z};
            ans += cy[p];
            if (my[p].find(y) != my[p].end()) {
                ans -= my[p][y];
            }
            my[p][y] += 1;
            cy[p] += 1;


            // for z differ
            p = {x, y};
            ans += cz[p];
            if (mz[p].find(z) != mz[p].end()) {
                ans -= mz[p][z];
            }
            mz[p][z] += 1;
            cz[p] += 1;
        }

        cout << ans << endl;
    };

    for (tc = 1; tc <= t; tc++) {
        solve();
    }

    return 0;
}

```

```c++
    // Life is a race...And I am just a viewer of that race ~ Pari_na_kisu

#include <bits/stdc++.h>
using namespace std;
#define endl  "\n"
using ll = long long;



int main() {

    int t = 1, tc;
    cin >> t;

    auto solve = [&] () -> void {
        ll n;
        cin >> n;
        vector<int> v(n);

        for (int i = 0; i < n; i++) {
            cin >> v[i];
        }

        map <tuple<int, int, int>, int> mp;

        ll ans = 0;

        for (int i = 0; i < n - 2; i++) {
            int a = v[i];
            int b = v[i+1];
            int c = v[i+2];

            int x = mp[{0, b, c}];
            int y = mp[{a, 0, c}];
            int z = mp[{a, b, 0}];
            int chk = mp[{a, b, c}];

            ans += (x + y + z) - (3 * chk);
            mp[{0, b, c}] += 1;
            mp[{a, 0, c}] += 1;
            mp[{a, b, 0}] += 1;
            mp[{a, b, c}] += 1;
        }

        cout << ans << endl;
    };

    

    for (tc = 1; tc <= t; tc++) {
        solve();
    }

    return 0;
}

```

## Problem links:
[B. Symmetric Encoding](https://codeforces.com/contest/1974/problem/C)
## Resources:

