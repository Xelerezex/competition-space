[23. Merge k Sorted Lists](https://leetcode.com/problems/merge-k-sorted-lists/)

You are given an array of `k` linked-lists `lists`, each linked-list is sorted in ascending order.

_Merge all the linked-lists into one sorted linked-list and return it._

__Example 1:__

    Input: lists = [[1,4,5],[1,3,4],[2,6]]
    Output: [1,1,2,3,4,4,5,6]
    Explanation: The linked-lists are:
    [
        1->4->5,
        1->3->4,
        2->6
    ]
    merging them into one sorted list:
    1->1->2->3->4->4->5->6

__Example 2:__

    Input: lists = []
    Output: []

__Example 3:__

    Input: lists = [[]]
    Output: []

__Constraints:__

- `k == lists.length`
- $0 \leq$ `k` $\leq 104$
- $0 \leq$ lists[i].length $\leq 500$
- $-10^4 \leq$ lists[i][j] $\leq 10^4$
- `lists[i]` is sorted in __ascending order__.
- The sum of `lists[i].length` will not exceed $10^4$.
