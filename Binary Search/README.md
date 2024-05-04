## Binary search code:
 `Return the index if the target is found. 
 If not, return the index where it would be if it were inserted in order.`
```c++
    while (i <= j) {
            int mid = i + (j -i)/2;

            if (nums[mid] < target) {
                i = mid + 1;
            } else if (nums [mid] > target) {
                j = mid - 1;
            } else {
                return mid;
            }
    }
    return l;
```




## Find First and Last Position of Element in Sorted Array
### Code:
```c++
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = (int)nums.size(), left = -1, right = -1;

        int i = 0, j = n - 1;
        while (i <= j) {
            int mid = i + (j -i)/2;

            if (nums[mid] < target) {
                i = mid + 1;
            } else if (nums [mid] > target) {
                j = mid - 1;
            } else {
                left = mid;
                j = mid - 1;
            }
        }

        i = 0, j = n - 1;
        while (i <= j) {
            int mid = i + (j -i)/2;

            if (nums[mid] < target) {
                i = mid + 1;
            } else if (nums [mid] > target) {
                j = mid - 1;
            } else {
                right = mid;
                i = mid + 1;
            }
        }
        return {left, right};
    }
};
```

### Lower bound function Implementation
### code:
```c++
 int l = 0, h = n -1, idx = n + 1;

while (l <= h) {
    int mid = l + (h-l)/2;

    if (v[mid] >= target){
        h = mid - 1;
        idx = mid;
    } else {
        l = mid + 1;
    }
}
if (idx == n + 1) {      // idx will remain same as intialized, this happens when target > v[last_index]
    cout << -1 << endl;
} else {
    cout << v[idx] << endl;
}
```

### upper bound function Implementation
### code:
```c++
 int l = 0, h = n -1, idx = n + 1;

while (l <= h) {
    int mid = l + (h-l)/2;

    if (v[mid] > target){
        h = mid - 1;
        idx = mid;
    } else {
        l = mid + 1;
    }
}
if (idx == n + 1) {      // idx will remain same as intialized, this happens when target > v[last_index]
    cout << -1 << endl;
} else {
    cout << v[idx] << endl;
}
```