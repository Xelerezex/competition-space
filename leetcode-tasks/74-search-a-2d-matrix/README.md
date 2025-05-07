[74. Search a 2D Matrix](https://leetcode.com/problems/search-a-2d-matrix/description/)

You are given an `m x n` integer matrix matrix with the following two properties:

- Each row is sorted in non-decreasing order.
- The first integer of each row is greater than the last integer of the previous row.

Given an integer `target`, return `true` if `target` is in `matrix` or `false` otherwise.

You must write a solution in `O(log(m * n))` time complexity.

__Example 1:__
    ![image](./../../images/74-task-matrix-1.jpg)

    Input: matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 3
    Output: true

__Example 2:__
    ![image](./../../images/74-task-matrix-2.jpg)
    
    Input: matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 13
    Output: false

__Constraints:__

- `m == matrix.length`
- `n == matrix[i].length`
- $1 \leq$ `m, n` $\leq 100$
- $-10^4 \leq$ `matrix[i][j], target` $\leq 10^4$
