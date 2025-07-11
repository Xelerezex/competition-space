﻿[138. Copy List with Random Pointer](https://leetcode.com/problems/copy-list-with-random-pointer/)

A linked list of length `n` is given such that each node contains an additional random pointer, which could point to any node in the list, or `null`.

Construct a [deep copy](https://en.wikipedia.org/wiki/Object_copying#Deep_copy) of the list. The deep copy should consist of exactly `n` __brand new__ nodes, where each new node has its value set to the value of its corresponding original node. Both the `next` and `random` pointer of the new nodes should point to new nodes in the copied list such that the pointers in the original list and copied list represent the same list state. __None of the pointers in the new list should point to nodes in the original list.__

For example, if there are two nodes `X` and `Y` in the original list, where `X.random --> Y`, then for the corresponding two nodes `x` and `y` in the copied list, `x.random --> y`.

Return the _head of the copied linked list._

The linked list is represented in the input/output as a list of n nodes. Each node is represented as a pair of `[val, random_index]` where:

- `val`: an integer representing `Node.val`
- `random_index`: the index of the node (range from `0` to `n-1`) that the random pointer points to, or `null` if it does not point to any node.

Your code will __only__ be given the `head` of the original linked list.

__Example 1:__

![image](./../../images/138-copy-list-with-random-pointer-1.png)

    Input: head = [[7,null],[13,0],[11,4],[10,2],[1,0]]
    Output: [[7,null],[13,0],[11,4],[10,2],[1,0]]

__Example 2:__

![image](./../../images/138-copy-list-with-random-pointer-2.png)

    Input: head = [[1,1],[2,1]]
    Output: [[1,1],[2,1]]

__Example 3:__

![image](./../../images/138-copy-list-with-random-pointer-3.png)

    Input: head = [[3,null],[3,0],[3,null]]
    Output: [[3,null],[3,0],[3,null]]

__Constraints:__

- $0 \leq $`n`$ \leq 1000$
- $-104 \leq $`Node.val`$ \leq 104$
- `Node.random` is `null` or is pointing to some node in the linked list.

