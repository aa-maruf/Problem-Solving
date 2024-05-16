## Problem Statement:
couldn't copy the problem. Link is given below.

## Solutions: 
```c++
int main() {

    int t = 1, tc;
    cin >> t;

    auto solve = [&] () -> void {
        int n, q ; cin >> n >> q;

        std::vector<ll> v(n), ans(n);

        for (auto &x :v ) cin >> x;

        multiset<int> st, mini;

        ll sum = v[0];
        ans[0] = sum;
        st.insert(v[0]);

        for (int i = 1; i < n; i++) {
            sum += v[i];
            st.insert(v[i]);

            if (i % 2 == 0) {
                sum -= 2 * (*st.begin());
                mini.insert(*st.begin());
                st.erase(st.find(*st.begin()));
                ans[i] = sum;
            } else {
                while (mini.size() and *st.begin() < *mini.rbegin()) {
                    sum -= 2 * (*st.begin());
                    sum += 2 * (*mini.rbegin());

                    int x = *st.begin(), y = *mini.rbegin();

                    st.insert(y), mini.insert(x);

                    st.erase(st.find(x)), mini.erase(mini.find(y));
                }
            }
        }

        for (int i = 0; i < q; i++) {
            int x; cin >> x;
            cout << ans[x - 1] << " ";
        }

        cout << endl;

    };
    for (tc = 1; tc <= t; tc++) {
        solve();
    }

    return 0;
}

```
## Problem links:
- [3out1in - codechef](https://www.codechef.com/problems/OKLAMA)

## Resources:
- [TLE Eliminator - youtube](https://youtu.be/j-ExCifW4k0?si=I6wa1_0rBkOAXlw1&t=1982)

