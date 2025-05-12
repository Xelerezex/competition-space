[4. Median of Two Sorted Arrays](https://leetcode.com/problems/median-of-two-sorted-arrays/)

Given two sorted arrays `nums1` and `nums2` of size `m` and `n` respectively, return __the median__ of the two sorted arrays.

The overall run time complexity should be `O(log (m+n))`.

__Example 1:__

    Input: nums1 = [1,3], nums2 = [2]
    Output: 2.00000
    Explanation: merged array = [1,2,3] and median is 2.

__Example 2:__

    Input: nums1 = [1,2], nums2 = [3,4]
    Output: 2.50000
    Explanation: merged array = [1,2,3,4] and median is (2 + 3) / 2 = 2.5.

__Constraints:__

- `nums1.length == m`
- `nums2.length == n`
- $0 \leq$ `m` $\leq 1000$
- $0 \leq$ `n` $\leq 1000$
- $1 \leq$`m + n` $\leq 2000$
- $-10^6 \leq$ `nums1[i], nums2[i]` $\leq 10^6$

