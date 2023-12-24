### Problem Statement:
![B. Make Almost Equal With Mod](/codeforces/Assets/B.%20Make%20Almost%20Equal%20With%20Mod.png)


### Problem :
```c++
    
void solve() {
    ll n;
    cin >> n;
    vector<ll> v(n);

    for (auto &x: v) cin >> x;

    for (ll i = 0; i < 64; i++) {
        set <int>s; 
        for (int j = 0; j < n; j++) {
            bool x = (v[j] & (1ll << i));
            s.insert(x);
            if (s.size () == 2){
                ll z = i + 1;
                ll ans = ( 1ll << z);
                cout << ans << endl;
                return;
            }
        }
        s.clear();    
    }  
}


int main() {

    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    ErroR();

    int t = 1;
    cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}

```
`Note : It can be done by exponent of 2 and and checking # of distinct element by 2, Don't give limit to pow of 2`</br>
`for (int i = 2; ; i *= 2)`


### Problem link :
- [B. Make Almost Equal With Mod](https://codeforces.com/contest/1909/submission/238585927)



