### Problem Statement:
Problem Statement
You are given a string 
S. Find the maximum length of a contiguous substring of 
S that is a palindrome.
Note that there is always a contiguous substring of 
S that is a palindrome.

Constraints</br>
S is a string of length between 
2 and 
100, inclusive, consisting of uppercase English letters. </br>
Input </br>
The input is given from Standard Input in the following format:
`S      ` </br>
Output</br>
Print the answer.

### Solution :
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


void solve() {
   string s;
   cin >> s;
   int n = s.size();
   int ans = 1;

   auto isPal = [&](int l, int r) 
   {
     for (int i = l, j = r; i < j; i++, j--) {
            if(s[i] != s[j])
                return false;
         }
        return true;
   };

   for (int i = 0; i < n ; i++) {
        for (int j = i + 1; j < n; j++) {
                if (isPal (i,j)) {
                    ans = max (ans, j - i + 1);
                }
        }
   }
   cout << ans << "\n";
   
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
    // cin >> t;

    while (t--) {
        solve();
    }

    cerr << endl << "Run Time : " << ((double)(clock() - z) / CLOCKS_PER_SEC);

    return 0;
}

```
#### Problem links:
- [B - Longest Palindrome](https://atcoder.jp/contests/abc320/tasks/abc320_b)