Problem statement:
![A. Odd Divisor](codeforces/../Assets/A.%20Odd%20Divisor.png)

## Intuition:
$2$ is the only even prime number. 


## Solution:
```c++

void solve() {
    ll n;
    cin >> n;

    double x = log2(n);

    if (x == (int)x) {
        cout << "NO" << endl;
    } else {
        cout << "YES" << endl;
    }
}
```

## Problem link:
- [A. Odd Divisor - codeforces (easy)](https://codeforces.com/contest/1475/problem/A)