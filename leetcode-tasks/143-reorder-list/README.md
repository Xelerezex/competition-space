[143. Reorder List](https://leetcode.com/problems/reorder-list/)

You are given the head of a singly linked-list. The list can be represented as:

$$
L_0 → L_1 → … → L_{n - 1} → L_n
$$

Reorder the list to be on the following form:

$$
L_0 → L_n → L_1 → L_{n - 1} → L_2 → L_{n - 2} → …
$$

You may not modify the values in the list's nodes. Only nodes themselves may be changed.

__Example 1:__

![image](./../../images/143-reorder-list-1.jpg)

    Input: head = [1,2,3,4]
    Output: [1,4,2,3]

__Example 2:__

![image](./../../images/143-reorder-list-2.jpg)

    Input: head = [1,2,3,4,5]
    Output: [1,5,2,4,3]

__Constraints:__

- The number of nodes in the list is in the range $[1, 5 * 10^4]$.
- $1 \leq$ `Node.val` $\leq 1000$
