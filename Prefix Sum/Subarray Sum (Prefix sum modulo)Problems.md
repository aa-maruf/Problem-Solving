### Prerequisite:
> Hashing and modular problem [two sum problem for divisible by k]:
> - https://leetcode.com/problems/count-pairs-that-form-a-complete-day-ii/ 
> - https://leetcode.com/problems/check-if-array-pairs-are-divisible-by-k/


### [**560. Subarray Sum Equals K with explanation of nyc_coder**](https://leetcode.com/problems/subarray-sum-equals-k/discuss/867435/MATH-BEHIND-PREFIX-SUM-PYTHON-EASY-TO-UNDERSTAND)

![nyc_coder](/Prefix%20Sum/Assets/image-1.png "nyc_coder")
![nyc_coder](/Prefix%20Sum/Assets/image-2.png "nyc_coder")

```c++
// try to do it without prefix array
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        vector<long long> pre(n + 1);

        partial_sum (nums.begin(), nums.end(), pre.begin() + 1); 

        for (auto &x : pre) **cout** <<x  << " ";

        map <long long, int> mp;
        int cnt = 0;

        for (int i = 0; i <= n; i++) {
            long long find = pre[i] - k;
            if (mp.find(find) != mp.end()) {
                cnt += mp[find];
            }
            mp[pre[i]]++;
        }
        return cnt;
    }
};
```

### [**974. Subarray Sums Divisible by K with explanation of nyc_coder**](https://leetcode.com/problems/subarray-sums-divisible-by-k/discuss/859080/DETAILED-EXPLANATION-OF-MATH-BEHIND-O(N)-SOLUTION)

![nyc_coder](/Prefix%20Sum/Assets/image-3.png "nyc_coder")
![nyc_coder](/Prefix%20Sum/Assets/image-4.png "nyc_coder")


`Better prob:`
> number = divisor × quotient + remainder
![CodeWithMIK](/Prefix%20Sum/Assets/image-6.png "CodeWithMIK")
`Means (s1- s2) are divisible by k if mods are same- `
 > $$s_1 \% k = x \quad \text{and} \quad s_2 \% k = x \quad \text{both are equal}$$

https://www.youtube.com/watch?v=7Xeorb721LQ

[Leetcode editorial](https://leetcode.com/problems/subarray-sums-divisible-by-k/editorial/)



```c++
// try to do it without prefix array
class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int n = nums.size();

        map <int, int> mp; // modGroups

        vector<int> prefix(n + 1);

        partial_sum (nums.begin(), nums.end(), prefix.begin() + 1);


        int ans = 0;
        for (int i = 0; i <= n; i++) {
             int prefixMod = (prefix[i] % k + k) % k;
             ans += mp[prefixMod];
             mp[prefixMod]++;
        }
        return ans;
    }
};
```


### [**1590. Make Sum Divisible by P - with explanation of nyc_coder**](https://leetcode.com/problems/make-sum-divisible-by-p/solutions/859173/detailed-explanation-of-math-behind-o-n-solution/?envType=daily-question&envId=2024-10-03)

![nyc_coder](/Prefix%20Sum/Assets/image-7.png "nyc_coder")
![nyc_coder](/Prefix%20Sum/Assets/image-8.png "nyc_coder")
![nyc_coder](/Prefix%20Sum/Assets/image-9.png "nyc_coder")


```c++
/*

|--------s1---------| s1 = sum1(0 : i) er sum
|-----s2-----|        s2 = sum2 (0: j)  er sum
(s1 - s2) % p = 0  [that means s1 & s2 divisible by p]
s1 % p = s2 % p    [if mod of s1 == x  and s2 == x then (s1 - s)2 % p == 0 confirm]
total = sum (0: n) 
any = sum (j : i)
if
total % p == any % p
mane (total - any) % p == 0 , So, (total - any) wiil be divisible b p
*/


class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        int n = nums.size();

        // Step 1: Calculate total sum and target remainder
        long long sum = accumulate (nums.begin(), nums.end(), 0ll);
        long long target = sum % p;
        if (target == 0) return 0;
        
        // Step 2: Use a hash map to track prefix sum mod p
        unordered_map<int,int> mp; // modMap
        mp[0] = -1;  // To handle the case where the whole prefix is the answer
        int minLen = n, currentSum = 0;

        // Step 3: Iterate over the array
        for (int i = 0; i < n; i++) {
            // Calculate what we need to remove
            currentSum = (currentSum + nums[i]) % p;
            int find = (currentSum - target + p) % p; // +p to avoid negative
            
            // If we have seen the needed remainder, we can consider this
            // subarray
            if (mp.find(find) != mp.end()) {
                minLen = min (minLen, i - mp[find]); // +1 kri nai karon find er por theke i ubdi
            }
            // Store the current remainder and index
            mp[currentSum]  = i;
        }
        // Step 4: Return result
        return minLen == n ? -1 : minLen;
    }
};
```

### Prefix xor parity problem :
> - https://leetcode.com/problems/find-the-longest-substring-containing-vowels-in-even-counts/
> - https://leetcode.com/problems/number-of-wonderful-substrings/ 
> - https://leetcode.com/problems/find-longest-awesome-substring/


### More problems:
- https://leetcode.com/problems/contiguous-array/




