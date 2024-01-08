### Problem statement:
![B. MKnez's ConstructiveForces Task](/Codeforces/Assets/B.%20MKnez's%20ConstructiveForces%20Task.png)


### Intuition:
$$ s_{(i−1)} + s_i =s_i + s_{(i+1)} $$
 which is equivalent to 
 $$ s_{(i−1)} =s_{(i+1)} $$

For odd:
 
 We know,
 
  $$(n/2) (n/2) - ((n/2)-1) ((n/2)+1) = 1 $$
  $$ so, (n/2) (n/2) + ((n/2)-1) *  -((n/2)+1) = 1 $$
  
  
  Example: For 7  [b a b a b a b]
  
  Here b= -((n/2)-1) = -2  [number of b is (n/2 +1) = 4]  so, 4 * -2 = -8
  Here a = n/2 = 3 [number of a is n/2 = 3]  so, 3 * 3 = 9
  a+b = 3 -2 =1
  sum of array = 9 - 8 =1
  
  
  Formula: highlight  
  
  suppose k= n/2;
  a= n/2, b =(n/2) -1
  
  For odd size n:      b  a b a b a b.... b     
  Number of a = n/2 = k
  number of b = n/2 + 1 = k + 1
  
  `Sum = k x a - (k+1) x b = 1`


### Editorial :
If n
 is even, the array [−1,1,−1,1,…,−1,1]
 is a solution. The sum of any two adjacent elements is 0
, as well as the sum of the whole array.

Suppose that n
 is odd now. Since si−1+si
 and si+si+1
 are both equal to the sum of the whole array for each i=2,3,…n−1
, it must also hold that si−1+si=si+si+1
, which is equivalent to si−1=si+1
. Let's fix s1=a
 and s2=b
. The condition above produces the array s=[a,b,a,b,…a,b,a]
 (remember that we consider an odd n
).

Let k
 be a positive integer such that n=2k+1
. The sum of any two adjacent elements is a+b
 and the sum of the whole array is (k+1)a+kb
. `Since the two values are equal`, means -
$$ (k+1)a + kb = a + b $$
we can conclude that 
$$ ka+(k−1)b=0 $$
$$ a=k−1
 and b=−k $$
 produces an answer. But, we must be careful with a=0
 and b=0
 since that is not allowed. If k=1
 then ka+(k−1)b=0
 implies ka=0
 and a=0
, so for n=2⋅1+1=3
 an answer does not exist. Otherwise, one can see that a=k−1
 and b=−k
 will be non-zero, which produces a valid answer. So, the array [k−1,−k,k−1,−k,…,k−1,−k,k−1]
 is an answer for k≥2
 (n≥5
)

---

### Solution:
```c++
void solve(){
    int n;
    cin>>n;
    if(n==3){
        cout<<"NO"<<endl;
        return;
    }
    else if(n%2==0){
        cout<<"YES"<<endl;

        for(int i=0;i<n/2;i++){
            cout<<"1 -1 ";
        }
        cout<<endl;
    }
    else {
        cout<<"YES"<<endl;
        int x= n/2;
        for(int i=0;i<n/2;i++){
            cout<<1-x<<" "<<x<<" ";
        }
        cout<<1-x<<endl;
    }
}
```

### Solution 2 :
```c++
void solve() {
    ll n;
    cin >> n;

    if (n == 1 || n == 3) {
        cout << "NO" <<   endl;
        return;
    } 

    cout << "YES" <<endl;
    if (n % 2 == 0) {
        for (int i = 0; i < n/2 ; i++) {
            cout<<"1 -1 ";
        }
        cout << endl;
        return;
    }
    for (int i = 0; i < n; i+= 2) {
        cout << 3 - n << " ";

        if (i != n-1)
            cout << n -1 << " ";
    }
    cout << endl;
    
}
```

### Problem link:
- [B. MKnez's ConstructiveForces Task](https://codeforces.com/contest/1779/problem/B)

### Resources:
- [Youtube video of 2nd solution - MUST WATCH](https://www.youtube.com/watch?v=2L326KCBqug)