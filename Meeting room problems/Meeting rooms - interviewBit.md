
---

## Problem Statement

Given a 2D integer array `A` of size `N x 2` denoting time intervals of different meetings, where `A[i][0]` is the start time of the i-th meeting and `A[i][1]` is the end time of the i-th meeting, determine the minimum number of conference rooms required so that all meetings can be conducted. 

Note that if a meeting ends at time `t`, another meeting starting at time `t` can use the same conference room.

### Constraints:

- `1 <= N <= 10^5`
- `0 <= A[i][0] < A[i][1] <= 2 * 10^9`

You are to implement a function that takes the matrix `A` as its only argument and returns the minimum number of conference rooms required.

---
## Solutions: 
```c++
// using min heap.
int Solution::solve(vector<vector<int> > &v) {
    sort (v.begin(), v.end());
    int n = v.size();
    
    priority_queue<int, vector<int>, greater<int>> pq; // min heap
    
    for (int i = 0; i < n; i++) {
        if (!pq.empty() and v[i][0] >= pq.top()) { // doesn't overlap
            pq.pop();
        }       
        pq.push(v[i][1]);
    }
    
    return pq.size();
}

```
```c++
// using line sweep algorithm
int Solution::solve(vector<vector<int> > &v) {
    map<int, int> timeline;
    for (int i = 0; i < v.size(); i++) {
        timeline[v[i][0]]++;
        timeline[v[i][1]]--;
    }
    long long prefix = 0, min_rooms = 0;
    for (auto &[f,s] : timeline) {
        prefix += s;
        min_rooms = max (prefix, min_rooms);
    }
    
    return min_rooms;
}
```


## Problem **links**:
- [Meeting rooms - interviewBit](https://www.interviewbit.com/problems/meeting-rooms/)
- [253. Meeting Rooms II - Leetcode premium😥](https://leetcode.com/problems/meeting-rooms-ii/description/)
- [2406. Divide Intervals Into Minimum Number of Groups - Leetcode Medium](https://leetcode.com/problems/divide-intervals-into-minimum-number-of-groups/description/ "same as meeting room")
## Similar problem links:
- [1854. Maximum Population Year - Leetcode easy](https://leetcode.com/problems/maximum-population-year/ "Sweep Line algorithm")
- [B. Equalize - Codeforces](https://codeforces.com/contest/1928/problem/B "1928B Sweep Line algorithm")

## Resources:
- [Intro to Line Sweep Algorithm - youtube](https://www.youtube.com/watch?v=UVLO44wb67c)

