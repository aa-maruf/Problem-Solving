**B. Turtle and an Infinite Sequence**

>> *Time limit per test: 1 second*

>> *Memory limit per test: 256 megabytes*


There is a sequence 
$$a_0, a_1, a_2, \dots$$ 
of infinite length. Initially a<sub>i</sub> = i for every non-negative integer `i`. After every second, each element of the sequence will simultaneously change. a<sub>i</sub> will change to 
$$a_{i-1} | a_i | a_{i+1}$$ 
for every positive integer `i`.a<sub>0</sub> will change to a<sub>0</sub> | a<sub>1</sub>. Here, `|` denotes bitwise OR.

Turtle is asked to find the value of a<sub>n</sub> after $$m$$ seconds. In particular, if `m = 0` , then he needs to find the initial value of
a<sub>n</sub> 
He is tired of calculating so many values, so please help him!

*Input*

Each test contains multiple test cases. The first line contains the number of test cases 
$$t (1 \leq t \leq 10^4)$$
The description of the test cases follows.

The first line of each test case contains two integers 
$$ n, m (0 <= n, m <= 10^9) $$

*Output*

For each test case, output a single integer — the value of $$a_n$$ after $$m$$ seconds.

*Example*

input
```
9
0 0
0 1
0 2
1 0
5 2
10 1
20 3
1145 14
19198 10
```
output
```
0
1
3
1
7
11
23
1279
19455
```
Note: After 1 second, the sequence 
$$[a_0, a_1, a_2, a_3, a_4, a_5]$$ 
will become 
$$[1, 3, 3, 7, 7, 7]$$
. After 2 seconds, the sequence will become 
$$[3, 3, 7, 7, 7, 7]$$

## Intuition
Bit manupulation problem. For range ( L to R) find the jth bit is set or not.<br>
`Note:` don't need to traverse. Find the block of L and R in jth bit. <br>
- If they are in same block and the block is odd then bit will set, else bit will unset. <br>
- And if they are not in same block then bit will always be set. Because there is always a set bit among two consequetive blocks.
## Solutions: 
```c++
    int main() {

    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    ErroR();

    int t = 1, tc;
    cin >> t;

    auto solve = [&] () -> void {
        ll n, m;
        cin >> n >> m;

        ll l, r, ans;
        l = max (0ll, n - m);
        r = n + m;
        ans = 0;

        for (int j = 0; j < 32; j++) {
            ll block_of_r = r / (1ll << j);
            ll block_of_l = l / (1ll << j);

            if (block_of_r != block_of_l) {
                ans |= (1 << j);
            }
            else if (block_of_r == block_of_l) {
                if (block_of_r % 2) ans |= (1 << j); 
            }
        }

        cout << ans << endl;
    };

    for (tc = 1; tc <= t; tc++) {
        solve();
    }

    return 0;
}
```

## Problem links:
[B. Turtle and an Infinite Sequence](https://codeforces.com/contest/1981/problem/B)

## Resources:
- [TLE POTD]([text](https://youtu.be/_s6HwvQf0VE?si=CTglp14a9pgDYigt&t=989))