
>Given the head of a singly linked list, reverse the list, and return the reversed list.

 

`Example 1:`


Input: head = [1,2,3,4,5]</br>
Output: [5,4,3,2,1]</br>
`Example 2:`

Input: head = [1,2] </br>
Output: [2,1] </br>
`Example 3:`

Input: head = []</br>
Output: []
 

Constraints:

The number of nodes in the list is the range [0, 5000].
-5000 <= Node.val <= 5000
 

Follow up: A linked list can be reversed either iteratively or recursively. Could you implement both?

---

## Solution -1 
```c++
    class Solution
{
    public:
    struct Node* reverseList(struct Node *head)
    {
       Node* curr = head;
       Node* prev = NULL;
       Node* next = head -> next;
       
       while (curr != NULL) {
           next = curr -> next;
           curr -> next = prev;
           prev = curr;
           curr = next;
       }
       return prev;
    }
};
```

## Solution 2 : (Recursion)
```c++
    class Solution {
public:
    ListNode* root;
    ListNode* reverseList(ListNode* head) {
           
            if(head == NULL || head -> next == NULL){
                root = head;
                return head;
            }
            reverseList(head -> next);
            ListNode* temp = head -> next;
            temp -> next = head;
            head -> next = NULL;
        
            return root;
    } 
};
```

---
Problem Links:
- [206. Reverse Linked List - LeetCode](https://leetcode.com/problems/reverse-linked-list/)
- [Reverse Linked List - GFG](https://practice.geeksforgeeks.org/problems/reverse-a-linked-list/1)