 ### Custom power function (Modular exponential/ Binary exponential):
- Easy iteration
```c++
long long int customPow (long long int base, long long int exponent, long long int mod) {
        long long int result  = 1;
        while (exponent > 0) {
            if (exponent % 2 == 1) {
                result = (result * base) % mod;
            }
            base = (base * base) % mod;
            exponent /= 2;
        }
        return result;
    }
```

-  CustomPow function using bit manipulation (same concept as prev) :
  ```c++
     long expo(long a, long b, long m){
        long ans = 1;
        while(b){
            if(b&1) ans = (ans * a) % m;
            a = (a * a) % m;
            b >>= 1;
        }
        return ans % m;
    }
  ```

- CustomPow function using recersion :
  ```c++
    int power(long long b, long long p, int m){
        if(p <= 0) return 1;
        long long t = power(b, p/2, m);
        t = ((t * t)%m);
        return (p%2)?(t * b)%m : t;
    }
  ```

### A function to return the GCD of two numbers
```c++
ll gcd(ll a, ll b) {
    if (b == 0) {
    return a;
    }
    return gcd(b, a % b);
}

```

### A function to return the LCM of two numbers
```c++
ll lcm(ll a, ll b) {
  return (a * b) / gcd(a, b);
}
```

### Basic Arithmetic:
-  $$(a ~~~mod~~~ m)+(b ~~~mod~~~ m)  mod~~~ m ~~~= (a+b)~~~  mod~~~ m ~~~$$
- $$(a ~~~mod~~~ m)−(b ~~~mod~~~ m)  ~~~mod~~~ m= (a−b ) ~~~mod~~~ m$$
- $$(a ~~~mod~~~ m)⋅(b ~~~mod~~~ m)  ~~~mod~~~ m=a⋅b  ~~~mod~~~ m$$

- [Solve This Problem - D. Divisible Pairs](/Modular%20Arithmetic/D.%20Divisible%20Pairs%20-%20codeforces.md)



  
