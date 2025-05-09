[33. Search in Rotated Sorted Array](https://leetcode.com/problems/search-in-rotated-sorted-array/)

There is an integer array `nums` sorted in ascending order (with __distinct__ values).

Prior to being passed to your function, `nums` is possibly rotated at an unknown pivot index `k` (`1 <= k < nums.length`) such that the resulting array is `[nums[k], nums[k+1], ..., nums[n-1], nums[0], nums[1], ..., nums[k-1]]` (__0-indexed__). For example, `[0,1,2,4,5,6,7]` might be rotated at pivot index `3` and become `[4,5,6,7,0,1,2]`.

Given the array nums after the possible rotation and an integer `target`, return the index of `target` if it is in `nums`, or `-1` if it is not in `nums`.

You must write an algorithm with `O(log n)` runtime complexity.

__Example 1:__

    Input: nums = [4,5,6,7,0,1,2], target = 0
    Output: 4

__Example 2:__

    Input: nums = [4,5,6,7,0,1,2], target = 3
    Output: -1

__Example 3:__

    Input: nums = [1], target = 0
    Output: -1

Constraints:

- $1 \leq$ `nums.length` $\leq 5000$
- $-10^4 \leq$ `nums[i]` $\leq 10^4$
- All values of `nums` are __unique__.
- nums is an ascending array that is possibly rotated.
- $-10^4 \leq$ target $\leq 10^4$
