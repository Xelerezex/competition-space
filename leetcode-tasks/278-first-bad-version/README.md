﻿[278. First Bad Version](https://leetcode.com/problems/first-bad-version/description/)

You are a product manager and currently leading a team to develop a new product. Unfortunately, the latest version of your product fails the quality check. Since each version is developed based on the previous version, all the versions after a bad version are also bad.

Suppose you have `n` versions `[1, 2, ..., n]` and you want to find out the first bad one, which causes all the following ones to be bad.

You are given an API `bool isBadVersion(version) `which returns whether `version` is bad. Implement a function to find the first bad version. You should minimize the number of calls to the API.

__Example 1:__

    Input: n = 5, bad = 4
    Output: 4
    Explanation:
    call isBadVersion(3) -> false
    call isBadVersion(5) -> true
    call isBadVersion(4) -> true
    Then 4 is the first bad version.

__Example 2:__

    Input: n = 1, bad = 1
    Output: 1

__Constraints:__

    $1 \leq$ bad $\leq$ n $\leq 2^31 - 1$

