﻿[19. Remove Nth Node From End of List](https://leetcode.com/problems/remove-nth-node-from-end-of-list/)

Given the `head` of a linked list, remove the $n^{th}$ node from the end of the list and return its head.

__Example 1:__

![image](./../../images/19-remove-nth-node-from-end-of-list-1.jpg)

    Input: head = [1,2,3,4,5], n = 2
    Output: [1,2,3,5]

__Example 2:__

    Input: head = [1], n = 1
    Output: []

__Example 3:__

    Input: head = [1,2], n = 1
    Output: [1]

__Constraints:__

- The number of nodes in the list is `sz`.
- $1 <= $`sz`$ <= 30$
- $0 <= $`Node.val`$ <= 100$
- $1 <= $`n`$ <= sz$

Follow up: Could you do this in one pass?
