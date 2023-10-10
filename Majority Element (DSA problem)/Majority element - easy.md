## Problem Statement :
Given an array nums of size n, return the majority element.

The majority element is the element that appears more than ⌊n / 2⌋ times. `You may assume that the majority element always exists in the array.`

 

Example 1:

Input: nums = [3,2,3]
Output: 3
Example 2:

Input: nums = [2,2,1,1,1,2,2]
Output: 2
 

Constraints:

n == nums.length
1 <= n <= 5 * 1e4
-109 <= nums[i] <= 1e9
 

Follow-up: Could you solve the problem in linear time and in O(1) space?

## Solution :
```c++
    
/// Brute force (TLE occurs)
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size(), ans;
        for (int i = 0; i < n; i++) {
            int cnt = 1;
            for (int j = i + 1; j < n; j++) {
                if (nums[i] == nums[j])
                    cnt++;     
            }
            if (cnt > n/2) {
                ans = nums[i];
                break;
            }
        }
        
        return ans;
    }
};

```

```c++
/// Hashing  nlogn
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int,int>m;
        for (auto x: nums) {
            m[x]++;
            if (m[x] > n/2) {
                return x;
            }
        }
        return -1;
    }
};

```


```c++

// Sorting ! O(n lg n)
// condition : Majority elemnt always exits in array.
// # of occurence of majority element > n/2.  11112 
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        sort (begin(nums),end(nums));
        return nums[nums.size()/2];     
    }
};

```

```c++
// Bit Operation - O(n .lgn)  SC: O(1)
// 0 (n * total bits)
// # of bits = lg(nums[i])
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int ans = 0, n = nums.size();
        for (int i = 0; i < 32 ; i++) {
            int cnt  = 0;
            for (auto x : nums) {
                    if ((x >> i) & 1)
                        cnt++;
                    if (cnt > n/2) 
                        ans = ans | 1 << i ; // ans += 1 << i;
            }
        }
        return ans;
/* Extra Part :
    * Checking # of occurence of candidate whether it is greater than n/2 or not
    * Although it's not required because question says -
    "The majority element always exists in the array."
*/
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            if (nums[i] == ans) 
                cnt++;
        }
        
        if (cnt > n/2)
            return ans;
        else
            return -1;
    }
};
```

```c++
// Boyer Moore voting algo
// TC: O(n) SC: 0(1)

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int vote = 0, candidate = -1,count = 0, n = nums.size();
        for (int i = 0; i < n; i++) {
            if (vote == 0) {
                candidate = nums[i];
                vote++;
            } else if (nums[i] != candidate) 
                vote--;
            else if (nums[i] == candidate) 
                vote++;
        }
        return candidate;
       // ^ Returned because in this problem it is declared that "majority element will always exits in the array". So checking occurence of candidate whether it is greater than n/2 or not is not required.
        for (auto x : nums) {  
            if (x == candidate)
                count++;
        }
        
        if (count > n/2)
            return candidate;
        else 
            return -1;
        
    }  
};
```

```c++
// We can make the prev algo more shorter. Here is the shorter version. 
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int candidate,vote=0;
        for(int i=0;i<nums.size();i++)
        {
            if(vote)
            {
                vote+=(nums[i]==candidate ? 1 : -1);
            }
            else
            {
                candidate=nums[i];
                vote=1;
            }
        }
        return candidate;
    }
};

```
## Problem links:
- [169. Majority Element - leetcode (easy)](https://leetcode.com/problems/majority-element/)
- [Majority Element - gfg(easy)](https://practice.geeksforgeeks.org/problems/majority-element-1587115620/1?utm_source=gfg&utm_medium=article&utm_campaign=bottom_sticky_on_article)

## Resources :
- [Explanation of solution using bit manipulation](https://www.geeksforgeeks.org/find-majority-element-using-bit-magic/ "gfg")
- [Article on Boyer Moore Algorithm](https://www.geeksforgeeks.org/boyer-moore-majority-voting-algorithm/ "gfg")
- [Striver's video](https://www.youtube.com/watch?v=nP_ns3uSh80)
- [Read the Boyer Moore Algorithm md file]()
