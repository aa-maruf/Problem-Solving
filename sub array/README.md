# while solving subarray problems check this conditions:
- whether the given array of positive integers or not?
- If both (pos + neg), then check whether the elements can be zero or not.
---
- For only positive we can use two's pointer concept (TC: O(n)) or binary searching (TC: O(nlogn) overall complexity) And for neg + pos we have to can use hashing (map) (TC: O(nlogn) overall complexity).
- If the resulting subarray is greater or greater-equal to target, then we can use upper_bound or two's pointer method . [but for that array must be consists of positive elemensts only. Else prefix_sum array won't be sorted.]