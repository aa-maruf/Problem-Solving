## Permuation - (all distinct elements)
[Link](http://leetcode.com/problems/permutations/)
```c++
class Solution2 {
public:

    vector<vector<int>> res;
    void rec (vector<int>& nums, vector<bool> &vis, vector<int>& tmp, int n) {
        if (tmp.size() == nums.size()) {   // edge case [is_solved()]
            res.push_back (tmp);
            return;
        }

        // choices
        for (int i = 0; i < n; i++) {

            if (!vis[i]) {                // controlled recursion [recursion => choices + decision]            
                vis[i] = true;            
                tmp.push_back (nums[i]);  // do   [Pass by reference]   

                rec (nums, vis, tmp, n); //  explore

                tmp.pop_back();         // undo
                vis[i] = false;
            }
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        int n = nums.size();
        vector<int> tmp;
        vector <bool> vis (n);

        rec (nums, vis, tmp, n);
        return res;
    } 
};


```

## Permutation - (contains Duplicate elements)
[Link](http://leetcode.com/problems/permutations-ii/)
```c++
class Solution {
    public:
    int n;
    vector<vector<int>> res;
    void rec (vector<int>& nums, vector<bool> &vis, vector<int>& tmp, int n) {
        if (tmp.size() == n) {
            res.push_back (tmp);
            return;
        }

        for (int i = 0; i < n; i++) {
            if (vis[i]) continue;
            if (i and nums[i] == nums[i - 1] and !vis[i - 1])  continue;  /// priotizing the prev duplicate value. It will always come first. then next one.

            vis [i] = true;
            tmp.push_back (nums[i]);
            rec (nums, vis, tmp, n);

            vis[i] = false;
            tmp.pop_back ();
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        int n = nums.size();
        sort (nums.begin(), nums.end());
        vector<bool> vis (n);
        vector<int> tmp;
         rec (nums, vis, tmp, n);

         return res;
    }
};

```
----
## Combination - (No duplicate elements):
[Link](http://leetcode.com/problems/combinations/)
```c++
class Solution {
public:
    vector<vector<int>> res;
    void rec (int n, int k, int curr, int cnt, vector<int>& tmp) {
        if (cnt == k) {   // edge case [is_solved()]
            res.push_back (tmp);
            return;
        }

        for (int i = curr; i <= n; i++) {     // choices + controlled recursion
            tmp.push_back (i);    //do
            rec (n, k, i + 1, cnt + 1, tmp);  //explore
            tmp.pop_back ();   //undo
        }
    }
    vector<vector<int>> combine(int n, int k) {
        vector<int> tmp;
        rec (n, k, 1, 0, tmp);
        return res;
    }
};
```

## Combination Sum - (No duplicate elements)
```c++
class Solution {
public:
    vector<vector<int>> res;
    void rec (vector<int>& candidates, int target, int n, int idx, vector<int>& tmp) {
        if (target == 0) {
            res.push_back (tmp);
            return;
        }

        for (int i = idx; i < n; i++) {     // choices
            if (target >= candidates[i]) {    // controlled recursion
                tmp.push_back (candidates[i]);     // do
                rec (candidates, target - candidates[i], n, i, tmp); // explore
                tmp.pop_back ();  // undo
            }
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        int n = candidates.size();
        vector<int> tmp;
        rec (candidates, target, n, 0, tmp);

        return res;
    }
};
```

## Combination Sum - [duplicate elements]
[Link](http://leetcode.com/problems/combination-sum-ii/)
```c++
class Solution {
public:
    vector<vector<int>> res;

    void rec (vector<int>& candidates, vector<bool> vis, int target, int n, int idx, vector<int>& tmp) {
        if (target == 0) {
            res.push_back (tmp);
            return;
        }

        for (int i = idx; i < n; i++) {
            if (vis[i]) continue;
            if (i and candidates[i] == candidates[i - 1] and !vis[i -1]) continue;
            if (target - candidates[i] < 0) continue;

            tmp.push_back (candidates[i]);
            vis[i] = true;
            rec (candidates, vis, target - candidates[i], n, i + 1, tmp);    
            tmp.pop_back();
            vis[i] = false; 
        }

    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        int n = candidates.size();
        vector<int> tmp; 
        sort (candidates.begin(), candidates.end());
        vector<bool> vis(n);
        rec (candidates, vis, target, n, 0, tmp);

        return res;
    }
};

```

Optimization of prev solution. Ignoring the `vis` array. Changing `i > 0` => `i > idx` 

[Link](https://leetcode.com/problems/combination-sum-ii/submissions/1796105930)
```c++
class Solution {
public:
    vector<vector<int>> res;

    void rec (vector<int>& candidates, int target, int n, int idx, vector<int>& tmp) {
        if (target == 0) {
            res.push_back (tmp);
            return;
        }

        for (int i = idx; i < n; i++) {
            if (i > idx and candidates[i] == candidates[i - 1]) continue;
            if (target - candidates[i] < 0) continue;

            tmp.push_back (candidates[i]);
            rec (candidates, target - candidates[i], n, i + 1, tmp);    
            tmp.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        int n = candidates.size();
        vector<int> tmp; 
        sort (candidates.begin(), candidates.end());
        rec (candidates, target, n, 0, tmp);

        return res;
    }
};

```

---

## Subset: (All distinct elements)
`Note:` [substring/subarray and subset are not same.](/Important%20Notes/README.md) <br>
[Link](https://leetcode.com/problems/subsets/)
```c++
class Solution {
public:
    vector<vector<int>> res {};
    void rec (vector<int>& nums, int n,  vector<int>& tmp, int idx) {
       res.push_back (tmp);

        for (int i = idx; i < n; i++) {
            tmp.push_back (nums[i]);
            rec (nums, n, tmp, i + 1);
            tmp.pop_back ();
        }
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();
        vector<int> tmp;
        rec (nums, n, tmp,0);
        return res;
    }
};

```
`Note`: ∑nCi = 2^n <br>
So, Subset (power set) is all possible combination of the set. <br>
TC : N * 2^n. N is for inserting into `res`.


## Subset (duplicate elements)
```c++
class Solution {
public:
    vector<vector<int>> res;
    void rec (vector<int>& nums, int n,  vector<int>& tmp, int idx) {
       res.push_back (tmp);

        for (int i = idx; i < n; i++) {
            if (i > idx and nums[i] == nums[i - 1]) continue;
            tmp.push_back (nums[i]);
            rec (nums, n, tmp, i + 1);
            tmp.pop_back ();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        int n = nums.size();
        vector<int> tmp;
        sort (nums.begin(), nums.end());
        rec (nums, n, tmp,0);
        return res;
    }
};
```


