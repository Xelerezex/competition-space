[203. Remove Linked List Elements](https://leetcode.com/problems/remove-linked-list-elements/)

Given the `head` of a linked list and an integer `val`, remove all the nodes of the linked list that has `Node.val == val`, and return _the new head_.

__Example 1:__

![image](./../../images/203-remove-linked-list-elements.jpg)

    Input: head = [1,2,6,3,4,5,6], val = 6
    Output: [1,2,3,4,5]

__Example 2:__

    Input: head = [], val = 1
    Output: []

__Example 3:__

    Input: head = [7,7,7,7], val = 7
    Output: []

__Constraints:__

- The number of nodes in the list is in the range [$0, 10^4$].
- $1 \leq$ `Node.val` $\leq 50$
- $0 \leq$ `val` $\leq 50$

