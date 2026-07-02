 > ### [read prefix sum modulo problems in prefix sum folder]
 
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


## Problems
| # | Problem Name | Code | Platform | Difficulty |
|---|---|---|---|---|
|1| [2961. Double Modular Exponentiation](https://leetcode.com/problems/double-modular-exponentiation/) | [Code](./2961.%20Double%20Modular%20Exponentiation.md)| LC| | 
|2| [D. Divisible Pairs](https://codeforces.com/contest/1931/problem/D)| [Code](./D.%20Divisible%20Pairs%20-%20codeforces.md)|CF| |
|3|[974. Subarray Sums Divisible by K - Leetcode](https://leetcode.com/problems/subarray-sums-divisible-by-k/description/)| [Code](./974.%20Subarray%20Sums%20Divisible%20by%20K.md)|LC|Medium|
|4| [Check Subset sum divisible by k -GeeksofrGeeks](https://www.geeksforgeeks.org/problems/subset-with-sum-divisible-by-m2546/1)| [Code](./Check%20Subset%20sum%20divisible%20by%20k.md)|GFG|Medium|






  
