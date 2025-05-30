﻿[86. Partition List](https://leetcode.com/problems/partition-list/)

Given the `head` of a linked list and a value `x`, partition it such that all nodes __less than__ `x` come before nodes __greater than or equal__ to `x`.

You should `preserve` the original relative order of the nodes in each of the two partitions.

__Example 1:__

![image](./../../images/86-partition-list-1.jpg)

    Input: head = [1,4,3,2,5,2], x = 3
    Output: [1,2,2,4,3,5]

__Example 2:__

    Input: head = [2,1], x = 2
    Output: [1,2]

__Constraints:__

    The number of nodes in the list is in the range [0, 200].
    -100 <= Node.val <= 100
    -200 <= x <= 200

