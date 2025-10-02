```c++
    #include<bits/stdc++.h>
using namespace std;

/// Prime factorization using sqrt method
int main () {
   int n; cin >> n;
   vector<int> ans;
   for (int i = 2; i * i <= n; i++) {
      if (n % i == 0){
         while (n % i == 0) {
            ans.push_back(i);
            n /= i;
         }
      }
   }
   if (n > 1) ans.push_back(n);

   sort (ans.begin(), ans.end());
   for (auto x: ans) cout << x << " ";
}
```

