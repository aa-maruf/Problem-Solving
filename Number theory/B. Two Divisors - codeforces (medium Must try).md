## Problem Statement:
![B. Two Divisors](codeforces/../Assets/B.%20Two%20Divisors.png)

## Solution :
```c++
bool prime (ll a) {
    for (int i = 2; i * i <= a ; i++) {
        if (a % i == 0)
            return 1;
    }
    return 0;
}

// A function to return the GCD of two numbers
ll gcd(ll a, ll b) {
  if (b == 0) {
    return a;
  }
  return gcd(b, a % b);
}

// A function to return the LCM of two numbers
ll lcm(ll a, ll b) {
  return (a * b) / gcd(a, b);
}

void solve() {
    ll a, b;
    cin >> a >> b;

    if (b % a == 0) 
        cout << b * (b/a) << endl;
    else 
        cout << lcm (b, a) << endl;
}
```

## Problem link: 
- [B. Two Divisors](https://youtu.be/6vbL_jd5Ghw?si=08_m_GEAxiMwWery&t=336)

## Resources:
- [TLE ELiminator's video](https://youtu.be/6vbL_jd5Ghw?si=08_m_GEAxiMwWery&t=336)