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
   for (auto x: ans) cout << x << " "; cout << endl;


   /// Number of divisors from prime factorization

   map<int, int> m;

   for (auto x : ans) m[x]++;

   int number_of_divisors = 1;

   for (auto &[f,s] : m) {
      number_of_divisors *= m[f] + 1;  
      // + 1 for 2^0 like 12 = 2^2 * 3;  
      // One possible divisor of 12 can be 2^0 * 3^0 = 1; 
      // then 2^0 * 3^1 = 3 can be another one, it goes on for # of 2 = 0,1,2 and # of 3 = 0,1.   total ways = 3 * 2 = 6
   }
   cout << number_of_divisors << endl;
}