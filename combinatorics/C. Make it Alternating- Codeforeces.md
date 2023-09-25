# Problem Statement:

![C. Make it Alternating](/combinatorics/Assets/image.png)


# Solution :

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

ll fact (ll x) {
    ll ans = 1;
    bug(x);
    while (x){
        ans *= x;
        x--;
    }
    bug(ans);
    return ans;
}


void solve() {
           string s;
           cin >> s;
           vector<ll> v; int j = -1;
           char compare = '2';  //random
           for (int i = 0; i < s.size(); i++) {
                if (s[i] == compare)
                    v[j]++;
                else {
                    compare = s[i];
                    v.push_back(1);
                    j++;
                }
           }
           ll modd = 998244353;
           ll min_operation = 0, seq = 1;
           for (auto x : v) {
                min_operation += (x-1); 
                seq = (seq * x) % modd;
           }
           //seq *= fact (min_operation);

           for (int i = 1; i <= min_operation; i++) {
                
                seq = (seq*i) % modd;
           }
            cout << min_operation<< " "<<seq <<endl;
           
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

Problem link :
- [C. Make it Alternating](https://codeforces.com/contest/1879/problem/C)

Intuition: 
- [Solution video](https://youtu.be/_S3NpzQyqDE?si=yDsFesC77DcU3Ndu&t=784)

