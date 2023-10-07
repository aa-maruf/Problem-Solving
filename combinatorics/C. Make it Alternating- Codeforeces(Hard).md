# Problem Statement:

![C. Make it Alternating](/combinatorics/Assets/C.%20Make%20it%20Alternating.png)


# Solution :

```c++
    
#include <bits/stdc++.h>

#define endl  "\n"

using namespace std;

using ll = long long;

void solve() {
           string s;
           cin >> s;
           vector<ll> v; int j = -1;
           char compare = '2';  //random
           for (int i = 0; i < s.size(); i++) {
                if (s[i] == compare)
                    v[j]++;
                else {
                    compare = s[i];
                    v.push_back(1);
                    j++;
                }
           }
           ll modd = 998244353;
           ll min_operation = 0, seq = 1;
           for (auto x : v) {
                min_operation += (x-1); 
                seq = (seq * x) % modd;
           }
           //seq *= fact (min_operation);

           for (int i = 1; i <= min_operation; i++) {
                
                seq = (seq*i) % modd;
           }
            cout << min_operation<< " "<<seq <<endl;
           
}

```

Problem link :
- [C. Make it Alternating](https://codeforces.com/contest/1879/problem/C)

Intuition: 
- [Solution video](https://youtu.be/_S3NpzQyqDE?si=yDsFesC77DcU3Ndu&t=784)

