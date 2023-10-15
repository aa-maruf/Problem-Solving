## Problem statement: 
![A. Is It a Cat?](/Remove%20Consecutive%20Characters/Assets/A.%20Is%20It%20a%20Cat.png)

## Problem link:
- [A. Is It a Cat?](https://codeforces.com/contest/1800/problem/A)

---

## Solution 1:
```c++
    #include <bits/stdc++.h>

#ifndef ONLINE_JUDGE
    #include "DEBUG.h"
#else
    #define debug(x)
    #define bug(...)
    #define ErroR()
#endif

#define endl  "\n"

using namespace std;

using ll = long long;


void solve() {
  ll n; cin >> n;
   string s; cin >> s;

   transform(s.begin(),s.end(),s.begin(),::tolower);
    
   auto last = unique (s.begin(),s.end());
   s.erase(last, s.end()); debug(s);

   cout << ((s == "meow") ? "YES\n" : "NO\n");   
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

## Solution -2 :
```c++
#include <bits/stdc++.h>

#ifndef ONLINE_JUDGE
    #include "DEBUG.h"
#else
    #define debug(x)
    #define bug(...)
    #define ErroR()
#endif

#define endl  "\n"

using namespace std;

using ll = long long;


void solve() {
  ll n; cin >> n;
   string s; cin >> s;
   string ans = "";
   transform(s.begin(),s.end(),s.begin(),::tolower);
   for (int i = 1; i <= n; i++) {
        if (s[i] != s[i-1])
            ans += s[i-1];
   }
   
   cout << ((ans== "meow") ? "YES\n" : "NO\n");   
   
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

## Solution -2 (using string as stack):
```c++
// Solution - 2 using string as stack
#include <bits/stdc++.h>

#ifndef ONLINE_JUDGE
    #include "DEBUG.h"
#else
    #define debug(x)
    #define bug(...)
    #define ErroR()
#endif

#define endl  "\n"

using namespace std;

using ll = long long;

void solve() {
        int n; cin >> n;
        string s; cin >> s;
        string ans = "";
        transform(s.begin(),s.end(),s.begin(),::tolower);
        for (auto c : s) {
            if (!ans.empty() && ans.back() == c) 
                ans.pop_back();
            ans.push_back(c);
        }
        cout << (ans == "meow" ? "YES\n" : "NO\n") ;
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

## Solution - 3 : (two's pointer approach - different style) 
```c++
// Solution - 3 using two's pointer different approach
#include <bits/stdc++.h>

#ifndef ONLINE_JUDGE
    #include "DEBUG.h"
#else
    #define debug(x)
    #define bug(...)
    #define ErroR()
#endif

#define endl  "\n"

using namespace std;

using ll = long long;

void solve() {
        int n; cin >> n;
        string s; cin >> s;
        string ans = "";
        transform(s.begin(),s.end(),s.begin(),::tolower);
        int j = 0;
        for (int i = 0; i < n; i++,j++) {
            s[j] = s[i];
            if (j > 0 && s[j] == s[j-1])
                j--;
        }
        s = s.substr(0,j);
        cout << (s == "meow" ? "YES\n" : "NO\n") ;
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

Resources:
- Solution -3 was the modified approach of this problem -  [1047. Remove All Adjacent Duplicates In String - Leetcode(Easy)](/Remove%20Consecutive%20Characters/1047.%20Remove%20All%20Adjacent%20Duplicates%20In%20String%20-%20Leetcode(Easy).md)
