You are given an array a1,a2,…,an of pairwise distinct integers from 0 to n. Consider the following operation:

consecutively for each i from 1 to n in this order, replace a[i] with MEX(a1,a2,…,an).</br>
Here MEX of a collection of integers c1,c2,…,cm is defined as the smallest non-negative integer x which does not occur in the collection c. For example, MEX(0,2,2,1,4)=3
 and MEX(1,2)=0.

Print the array after applying k such operations.

`Input`</br>
Each test contains multiple test cases. The first line contains the number of test cases t
 (1≤t≤105). The description of the test cases follows.

The first line of each test case contains two integers n
 and k(1≤n≤1e5, 1≤k≤1e9).

The second line contains n
 pairwise distinct integers a1,a2,…,an
 (0≤ai≤n) representing the elements of the array before applying the operations.

It is guaranteed that the sum of n over all test cases does not exceed 105.

Output </br>
For each test case, print all nelements of the array after applying k operations.

`Example` </br>
inputCopy </br>
```C++
5
1 2
1
3 1
0 1 3
2 2
0 2
5 5
1 2 3 4 5
10 100
5 3 0 4 2 1 6 9 10 8
```
outputCopy </br>
```c++
1
2 0 1
2 1
2 3 4 5 0
7 5 3 0 4 2 1 6 9 10
```
Note </br>
In the first test case, here is the entire process:

On the first operation, the array changes from [1]
 to [0]
, since MEX(1)=0 
.
On the second operation, the array changes from [0]
 to [1]
, since MEX(0)=1
.
Thus, the array becomes [1]
 after two operations.

In the second test case, the array changes as follows during one operation: [0–,1,3]→[2,1–,3]→[2,0,3–]→[2,0,1]
.

In the third test case, the array changes as follows during one operation: [0–,2]→[1,2–]→[1,0]
. And during the second operation: [1–,0]→[2,0–]→[2,1]
. 

## Solution - 1: 

```C++
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
    
    ll n, k;  cin >> n >> k;
    vector<ll> v(n + 1);
    ll sum = 0;
    for (int i = 0; i < n ; i++) {
        cin >> v[i];
        sum += v[i];
    } 
    v[n] =  ((n+1) * n) /2    -  sum;

    k = k % (n+1);
    int x = (n + 1 - k) % (n  + 1);
    bug(x);
    debug(v);
    for (int i = 0; i < n; i++) {
        cout << v[x] << " \n"[i == (n-1)];
        x += 1;
        x = (x == (n + 1)) ? 0 : x;
    } 
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
    cin >> t;

    while (t--) {
        solve();
    }

    cerr << endl << "Run Time : " << ((double)(clock() - z) / CLOCKS_PER_SEC);
    
    return 0;
}
```
---
Link : https://codeforces.com/contest/1863/problem/C </br>
Explanation: [Youtube video - TLE](https://youtu.be/HKSMaNH6nDQ?si=SAqN2ymIafEoOgP4&t=578)
