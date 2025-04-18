[239. Sliding Window Maximum](https://leetcode.com/problems/sliding-window-maximum/)

You are given an array of integers `nums`, there is a sliding window of size `k` which is moving from the very left of the array to the very right. You can only see the `k` numbers in the window. Each time the sliding window moves right by one position.

Return the _max sliding window_.

__Example 1:__

    Input: nums = [1,3,-1,-3,5,3,6,7], k = 3
    Output: [3,3,5,5,6,7]
    Explanation: 
    Window position                Max
    ---------------               -----
    [1  3  -1] -3  5  3  6  7       3
    1  [3  -1  -3] 5  3  6  7       3
    1   3 [-1  -3  5] 3  6  7       5
    1   3  -1 [-3  5  3] 6  7       5
    1   3  -1  -3 [5  3  6] 7       6
    1   3  -1  -3  5 [3  6  7]      7

__Example 2:__

    Input: nums = [1], k = 1
    Output: [1]

__Constraints:__

- $1 \leq$ `nums.length` $\leq 10^5$
- $-10^4 \leq$ `nums[i]` $\leq 10^4$
- $1 \leq$ `k` $\leq$ `nums.length`

