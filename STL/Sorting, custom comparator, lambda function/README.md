### when you have to concatinate string and find which is lexicographically smallest or largest.
- https://leetcode.com/problems/largest-number/
- https://leetcode.com/problems/maximum-possible-number-by-binary-concatenation/
```c++
    vector<stirng> str = {"123", "223", "234", "333"};
    sort (str.begin(), str.end(), [&] (const string &a, const string &b){
            return (a + b) > (b + a); // largest
        }); 

    string ans = "";

    for (auto &x : str ) ans += x;
    cout << ans << endl;
```
