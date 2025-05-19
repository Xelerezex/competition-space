[141. Linked List Cycle](https://leetcode.com/problems/linked-list-cycle/)

Given `head`, the head of a linked list, determine if the linked list has a cycle in it.

There is a cycle in a linked list if there is some node in the list that can be reached again by continuously following the `next` pointer. Internally, `pos` is used to denote the index of the node that tail's `next` pointer is connected to. __Note that__ `pos` __is not passed as a parameter__.

Return `true` if there is a cycle in the linked list. Otherwise, return `false`.

__Example 1:__

![image](./../../images/141-linked-list-cycle-1.png)

    Input: head = [3,2,0,-4], pos = 1
    Output: true
    Explanation: There is a cycle in the linked list, where the tail connects to the 1st node (0-indexed).

__Example 2:__

![image](./../../images/141-linked-list-cycle-2.png)

    Input: head = [1,2], pos = 0
    Output: true
    Explanation: There is a cycle in the linked list, where the tail connects to the 0th node.

__Example 3:__

![image](./../../images/141-linked-list-cycle-3.png)

    Input: head = [1], pos = -1
    Output: false
    Explanation: There is no cycle in the linked list.

__Constraints:__

- The number of the nodes in the list is in the range [0, 104].
- $-10^5 \leq $Node.val$ \leq 10^5$
- `pos` is `-1` or a _valid index_ in the linked-list.

__Follow up__: Can you solve it using $O(1)$ (i.e. constant) memory?
