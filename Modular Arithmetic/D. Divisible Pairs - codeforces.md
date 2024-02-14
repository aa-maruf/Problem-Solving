## Problem Statement:
![D. Divisible Pairs](/Modular%20Arithmetic/Assests/D.%20Divisible%20Pairs-%20codeforces.png "Problem Statement")

## Intuition
#### Given condition ,
$$ (A_i - A_j) ~~~mod~~~ y == 0 $$
$$ (A_i + A_j) ~~~mod~~~ x == 0 $$

>Find # of Pairs in array which satisfies the both condition ?

Here,

$$ (A_i - A_j) ~~~mod~~~ y == 0 $$
$$ (A_i - A_j + A_j) ~~~mod~~~ y = A_j ~~~mod~~~ y $$
$$ A_i ~~~mod~~~ y = A_j ~~~mod~~~ y $$

And, 
$$ (A_i + A_j) ~~~mod~~~ x == 0 $$
$$ ((A_i ~~~mod~~~ x) + (A_j ~~~mod~~~ x)) ~~~mod~~~ x = (A_i + A_j) ~~~mod~~~ x = 0 $$
Since,
$$ ((A_i ~~~mod~~~ x) + (A_j ~~~mod~~~ x)) ~~~mod~~~ x == 0 $$ 
Hence,
$$ A_j = x - (A_i ~~~mod~~~ x) $$

So, we get ->
$$ A_i ~~~mod~~~ y = A_j ~~~mod~~~ y $$
$$ A_j = x - (A_i ~~~mod~~~ x) $$

## Approach
2 sum approach


## Solutions: 
```c++
void solve() {

    ll n, x, y;
    cin >> n >> x >> y;

    vector<ll> v(n);

    for (auto &val : v) {
        cin >> val;
    }

    map<pair<ll,ll>, ll> map;
    ll ans = 0;

    for (int i = 0; i < n; i++) {
        ll a = (x - (v[i] % x)) % x;
        ll b = v[i] % y;

        pair<ll,ll> z = {a, b};

        if (map.find(z) != map.end()) {
            ans += map[z];
        } 

        map[{v[i] % x, v[i] % y}]++;
    }
    cout << ans << endl;
}
```


## Problem links:
- [D. Divisible Pairs](https://codeforces.com/contest/1931/problem/D)

## Resources:
- [CF Article](https://codeforces.com/blog/entry/72527)
- [TLE Eliminator's video](https://youtu.be/GcLpb6r2R5A?si=WBkkcChjU2zHqj5U&t=1978)

