## Learning/ Intuition:
Here we have to make a/b == c/d by multiplying any number with any of the fractions nominator or denominator. How many multiplications are required?
Now, let say if we multiply x with c/d then both the fraction will be same.
then what will be x?

First we make c/d to 1 by multiplying with d/c.
so, c/d * d/c = 1
Now, multiply with a/b and it will become a/b
(c/d) * (d/c) * (a/b) = (a/b)

comparing it with, (c/d) * x = (a/b)  

we get x = (d/c) * (a/b) = (a * d) / (c * b)

So, if we multiply this x  with (c/b) we will get a/b == c/d

Now, if x == 1 it means we don't need multiply anything with c/d. In another way we can say both fraction are already same.
so, no of operation required is 0

if x = 4 (assume) means we have to multiply 4 with (c/d) to make two fraction equal.  
so, number of operation required is 1
if x = 1/4 (assume) means we have to multiply 4 with (a/b)
so, number of operation required is 1

if x = 3/4 means we have to multiply 3 with (c/d) and 4 with (a/b). 
Becuase (a/b) = x * (c/d)
So, number of operation required is 2

Number of operation will not exceed 2.

## Problem statement:
![A. Burenka Plays with Fractions](/Number%20theory/Assets/A.%20Burenka%20Plays%20with%20Fractions%20-Codeforces.png)

## Problem Link :
[A. Burenka Plays with Fractions](https://codeforces.com/problemset/problem/1720/A)

## Solution :
```c++
    
#include <bits/stdc++.h>

#define endl  "\n"

using namespace std;

using ll = long long;

void solve() {
              
    ll a,b,c,d ;
    int ans = 0;
    cin >> a >> b >> c >> d;

    if ( a == 0 && a == c) 
        cout << 0 << endl;
    else if (a == 0 || c == 0) 
        cout << 1 << endl;
    else {
          ll nominator = a * d * 1ll, denominator = b * c * 1ll;
          if (nominator == denominator)
            cout << 0 << endl;
          else if (nominator % denominator == 0)
            cout << 1 << endl;
          else if (denominator % nominator == 0)
            cout<< 1 << endl;
          else 
             cout << 2 << endl; 
    }
}
```

## Solution - 2:
```c++
    ///Jiangly's solve
    #include <bits/stdc++.h>

using i64 = long long;

void solve() {
    int a, b, c, d;
    std::cin >> a >> b >> c >> d;
    
    i64 x = 1LL * a * d;
    i64 y = 1LL * b * c;
    
    if (x == y) {
        std::cout << 0 << "\n";
    } else if ((y && x % y == 0) || (x && y % x == 0)) {
        std::cout << 1 << "\n";
    } else {
        std::cout << 2 << "\n";
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int t;
    std::cin >> t;
    
    while (t--) {
        solve();
    }
    
    return 0;
}

```