[25. Reverse Nodes in k-Group](https://leetcode.com/problems/reverse-nodes-in-k-group/)

Given the `head` of a linked list, reverse the nodes of the list `k` at a time, and return the modified list.

`k` is a positive integer and is less than or equal to the length of the linked list. If the number of nodes is not a multiple of `k` then left-out nodes, in the end, should remain as it is.

You may not alter the values in the list's nodes, only nodes themselves may be changed.

__Example 1:__

![image](./../../images/25-reverse-nodes-in-k-group-1.jpg)

    Input: head = [1,2,3,4,5], k = 2
    Output: [2,1,4,3,5]

__Example 2:__

![image](./../../images/25-reverse-nodes-in-k-group-2.jpg)

    Input: head = [1,2,3,4,5], k = 3
    Output: [3,2,1,4,5]

__Constraints:__

- The number of nodes in the list is `n`.
- $1 \leq$ `k` $<=$ `n` $\leq 5000$
- $0 \leq$ `Node.val` $\leq 1000$

__Follow-up:__ Can you solve the problem in $$O(1)$$ extra memory space?