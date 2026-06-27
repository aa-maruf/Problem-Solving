```c++
auto solve = [&] () -> void {
            
        ll a, b, x; cin >> a >> b >> x;
 
        if (a == b) {
            cout << 0 << endl;
            return;
        }
 
 
        ll cnt = 0, ans = 1e9;
 
        while (a != b) {
            if (b > a) swap (a, b);
 
            ans = min (cnt + (a - b), ans);
            a /= x;
            cnt++;
        }
        cout << min (cnt, ans) << endl;
  };
```