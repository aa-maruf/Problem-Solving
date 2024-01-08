## Binary search code:

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
    return -1;
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
 int i =0, j = n - 1, ans = n + 1;
 while (i <= j) {
        int mid = i + (j-i)/2;

        if (v[mid] >= 3){
            j = mid - 1;
            ans = mid;
        } else{
            i = mid + 1;
        }
    }
    if (ans == n + 1) {
        cout << -1 << endl;
    }
```