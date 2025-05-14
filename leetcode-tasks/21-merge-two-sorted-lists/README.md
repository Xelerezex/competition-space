[21. Merge Two Sorted Lists](https://leetcode.com/problems/merge-two-sorted-lists/)

You are given the heads of two sorted linked lists `list1` and `list2`.

Merge the two lists into one sorted list. The list should be made by splicing together the nodes of the first two lists.

Return the head of the merged linked list. 

__Example 1:__

    ![images](./../../images/21-merge-two-sorted-lists.jpg)

    Input: list1 = [1,2,4], list2 = [1,3,4]
    Output: [1,1,2,3,4,4]

__Example 2:__

    Input: list1 = [], list2 = []
    Output: []

__Example 3:__

    Input: list1 = [], list2 = [0]
    Output: [0]

__Constraints:__

- The number of nodes in both lists is in the range `[0, 50]`.
- $-100 \leq$ Node.val $\leq 100$
- Both `list1` and `list2` are sorted in non-decreasing order.
