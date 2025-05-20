[287. Find the Duplicate Number](https://leetcode.com/problems/find-the-duplicate-number/)

Given an array of integers `nums` containing `n + 1` integers where each integer is in the range `[1, n]` inclusive.

There is only one repeated number in `nums`, return _this repeated number_.

You must solve the problem without modifying the array `nums` and using only constant extra space.

__Example 1:__

    Input: nums = [1,3,4,2,2]
    Output: 2

__Example 2:__

    Input: nums = [3,1,3,4,2]
    Output: 3

__Example 3:__

    Input: nums = [3,3,3,3,3]
    Output: 3

__Constraints:__

- $1 \leq $`n`$ \leq 105$
- `nums.length == n + 1`
- $1 \leq $`nums[i]`$ \leq n$
- All the integers in `nums` appear only __once__ except for __precisely one integer__ which appears two or more times.

__Follow up:__

- How can we prove that at least one duplicate number must exist in `nums`?
- Can you solve the problem in linear runtime complexity?
