#### Problem Link: [2241B - Good times Good times](https://codeforces.com/contest/2241/problem/B)

#### Try this: [Divisilbility Trick](./divisibility%20trick.md)

#### Prove : [Editorial - 2241B - Good times Good times](https://codeforces.com/blog/entry/154698)

```c++
#include <bits/stdc++.h>
 
 
#define endl "\n"

#define ll long long

using namespace std;
 

void solve(){
    ll x;
    cin >> x;
    ll y = 1;

    while (x) {
        y *= 10;
        x /= 10;
    }

    cout << y + 1 << endl;
}




int main(){
    int t=1;
    cin>>t;
    while(t--){
        solve();
    }
}
```


